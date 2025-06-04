#include "WeaverCore.h"
#include <QDir>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>

WeaverCore::WeaverCore(const QString &templateDir, const QString &inputDir, const QString &outputDir)
    : templateDir(templateDir), inputDir(inputDir), outputDir(outputDir)
{}

void WeaverCore::process()
{
    // Placeholder: implement parsing, random template selection, and output
    log("Processing started");

    QDir templates(templateDir);
    QStringList templateFiles = templates.entryList(QStringList("*.html"), QDir::Files);
    int templateCount = templateFiles.size();

    if (templateCount == 0) {
        log("No templates found");
        return;
    }

    // Example of random selection
    int randomIndex = QRandomGenerator::global()->bounded(templateCount);
    QString chosenTemplate = templateFiles[randomIndex];
    log("Chosen template: " + chosenTemplate);

    // Here you would implement: read input files, split blocks, replace markers, write outputs
    // --- AGGIUNGI QUESTO CODICE QUI ---
    // Leggi il contenuto del template scelto
    QString chosenTemplatePath = templateDir + "/" + chosenTemplate;
    QFile templateFile(chosenTemplatePath);
    if (!templateFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        log("Cannot open template: " + chosenTemplatePath);
        return;
    }
    QString templateContent = QTextStream(&templateFile).readAll();
    templateFile.close();

    // Cerca tutti i file .wvr nella cartella input
    QDir input(inputDir);
    QStringList wvrFiles = input.entryList(QStringList("*.wvr"), QDir::Files);
    if (wvrFiles.isEmpty()) {
        log("No .wvr files found in input directory.");
        return;
    }

    for (const QString& wvrFileName : wvrFiles) {
        QFile wvrFile(inputDir + "/" + wvrFileName);
        if (!wvrFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            log("Cannot open .wvr file: " + wvrFileName);
            continue;
        }
        QString wvrContent = QTextStream(&wvrFile).readAll();
        wvrFile.close();

        // Sostituisci {{content}} nel template con il contenuto del .wvr
        QString outputHtml = templateContent;
        outputHtml.replace("{{content}}", wvrContent);

        // Salva il file HTML nella cartella di output con lo stesso nome base
        QString baseName = wvrFileName;
        baseName.chop(4); // Togli ".wvr"
        QString outputPath = outputDir + "/" + baseName + ".html";
        QFile outFile(outputPath);
        if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            log("Cannot write to output: " + outputPath);
            continue;
        }
        QTextStream out(&outFile);
        out << outputHtml;
        outFile.close();
        log("Generated: " + outputPath);
    }

    log("Processing finished");
}

void WeaverCore::log(const QString &message)
{
    QFile logFile(outputDir + "/log.txt");
    if (logFile.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&logFile);
        out << message << "\n";
    }
}
