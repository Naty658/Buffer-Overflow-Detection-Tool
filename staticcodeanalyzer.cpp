#include "staticcodeanalyzer.h"
#include "ui_staticcodeanalyzer.h"

StaticCodeAnalyzer::StaticCodeAnalyzer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StaticCodeAnalyzer)
{
    ui->setupUi(this);

    connect(ui->btnLoadFile, &QPushButton::clicked, this, &StaticCodeAnalyzer::loadFile);
    connect(ui->btnAnalyze, &QPushButton::clicked, this, &StaticCodeAnalyzer::analyzeCode);
}

void StaticCodeAnalyzer::loadFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open C++ Source File", "", "C++ Files (*.cpp *.h)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file: " + fileName);
        return;
    }

    QTextStream in(&file);
    currentFileContent = in.readAll();
    ui->textEditor->setText(currentFileContent);
    file.close();
}

/*
void StaticCodeAnalyzer::analyzeCode()
{
    if (currentFileContent.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file loaded");
        return;
    }

    // Simple static analysis: Find classes, functions, and variables

    QString result;
    QRegularExpression classExp("\\bclass\\s+\\w+");
    QRegularExpression funcExp("\\b\\w+\\s*\\([^\\)]*\\)\\s*\\{");
    QRegularExpression varExp("\\b\\w+\\s+\\w+;");

    int classCount = currentFileContent.count(classExp);
    int funcCount = currentFileContent.count(funcExp);
    int varCount = currentFileContent.count(varExp);

    result += "Classes Found: " + QString::number(classCount) + "\n";
    result += "Functions Found: " + QString::number(funcCount) + "\n";
    result += "Variables Found: " + QString::number(varCount) + "\n";

    ui->labelResult->setText(result);
}
*/


void StaticCodeAnalyzer::analyzeCode()
{
    if (currentFileContent.isEmpty()) {
        QMessageBox::warning(this, "Error", "No file loaded");
        return;
    }

    // Unsafe patterns related to functions prone to buffer overflows
    QRegularExpression unsafePatterns[] = {
        QRegularExpression("\\bstrcpy\\s*\\("),   // Match strcpy function
        QRegularExpression("\\bstrcat\\s*\\("),   // Match strcat function
        QRegularExpression("\\bstrcmp\\s*\\("),   // Match strcmp function
        QRegularExpression("\\bstrncat\\s*\\(\\s*[^,]*,[^,]*\\s*,\\s*[^,]*\\s*\\)"), // unsafe usage
        QRegularExpression("\\bscanf\\s*\\("),    // Match scanf function
        QRegularExpression("\\bfscanf\\s*\\("),   // Match fscanf function
        QRegularExpression("\\bsscanf\\s*\\("),   // Match sscanf function
        QRegularExpression("\\bgets\\s*\\("),     // Match gets function
        QRegularExpression("char\\s*\\*"),        // Match char pointer
        QRegularExpression("\\bchar\\s+\\w+\\s*\\[\\d+\\]"), // Match fixed size char arrays
        QRegularExpression("\\breinterpret_cast\\s*\\("), // Match reinterpret_cast
        QRegularExpression("\\bstrtok\\s*\\("),   // Match strtok function
        QRegularExpression("\\bsprintf\\s*\\("),  // Match sprintf function
        QRegularExpression("std::cin")            // Match std::cin
    };

    QStringList foundPatterns;
    QStringList possibleOverflows;

    // Check for unsafe patterns in the code
    for (const auto& pattern : unsafePatterns) {
        QRegularExpressionMatchIterator matchIter = pattern.globalMatch(currentFileContent);

        // For each match found, append the matched keyword from the code
        while (matchIter.hasNext()) {
            QRegularExpressionMatch match = matchIter.next();
            QString matchedText = match.captured(0); // Capture the whole match

            // Append the matched unsafe keyword to the found patterns list
            foundPatterns.append(matchedText);
        }

        // Additional checks for unsafe buffer-overflow risks like `strcpy` and `scanf`
        if (pattern.pattern() == "\\bstrcpy\\s*\\(") {
            QRegularExpression bufferSizePattern("\\bstrcpy\\s*\\(([^,]+),\\s*([^)]+)\\)");
            QRegularExpressionMatchIterator matchIter = bufferSizePattern.globalMatch(currentFileContent);
            while (matchIter.hasNext()) {
                QRegularExpressionMatch match = matchIter.next();
                QString destBuffer = match.captured(1); // Destination buffer
                QString srcString = match.captured(2); // Source string

                // Here you can add logic to compare buffer sizes, or look for hardcoded values or warnings
                if (destBuffer.length() > 10) { // Example check: if buffer length is too small for the string
                    possibleOverflows.append("Potential buffer overflow with strcpy: " + destBuffer);
                }
            }
        }

        if (pattern.pattern() == "\\bscanf\\s*\\(") {
            QRegularExpression scanfPattern("\\bscanf\\s*\\(\\s*\"%[a-zA-Z0-9%]+\"\\s*,\\s*[^)]+\\)");
            QRegularExpressionMatchIterator scanfIter = scanfPattern.globalMatch(currentFileContent);
            while (scanfIter.hasNext()) {
                QRegularExpressionMatch match = scanfIter.next();
                QString formatString = match.captured(1); // Format string
                // Check for format specifiers that can lead to buffer overflows
                if (formatString.contains("%s") && !formatString.contains("%[0-9]")) {
                    possibleOverflows.append("Potential buffer overflow risk with scanf: " + match.captured(0));
                }
            }
        }
    }

    // Display results
    if (!foundPatterns.isEmpty() || !possibleOverflows.isEmpty()) {
        QString result = "Unsafe Patterns Found:\n" + foundPatterns.join("\n");
        result += "\n\nPossible Buffer Overflow Risks:\n" + possibleOverflows.join("\n");
        ui->labelResult->setText(result);
    } else {
        ui->labelResult->setText("No unsafe patterns or buffer overflow risks found.");
    }
}

StaticCodeAnalyzer::~StaticCodeAnalyzer()
{
    delete ui;
}
