#ifndef KOREANPLUGIN_H
#define KOREANPLUGIN_H

#include <QObject>
#include <QThread>
#include "languageplugininterface.h"
#include "abstractlanguageplugin.h"

class KoreanLanguageFeatures;

class KoreanPlugin : public AbstractLanguagePlugin
{
    Q_OBJECT
    Q_INTERFACES(LanguagePluginInterface)
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.Examples.KoreanPlugin" FILE "koreanplugin.json")

public:
    explicit KoreanPlugin(QObject* parent = 0);
    virtual ~KoreanPlugin();
    virtual AbstractLanguageFeatures* languageFeature();

    virtual void predict(const QString& surroundingLeft, const QString& preedit);
    virtual void wordCandidateSelected(QString word);

signals:
    void newPredictionSuggestions(QString word, QStringList suggestions);
    void parsePredictionText(QString preedit);
    void candidateSelected(QString word);

public slots:
    void finishedProcessing(QString word, QStringList suggestions);

private:
    KoreanLanguageFeatures* m_koreanLanguageFeatures;
    QString m_nextWord;
    bool m_processingWord;
};

#endif // JAPANESEPLUGIN_H
