#pragma once

#include <QString>

class WeaverCore
{
public:
    WeaverCore(const QString &templateDir, const QString &inputDir, const QString &outputDir);
    void process();

private:
    QString templateDir;
    QString inputDir;
    QString outputDir;
    void log(const QString &message);
};

