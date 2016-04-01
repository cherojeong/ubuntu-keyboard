#include "koreanplugin.h"
#include "koreanlanguagefeatures.h"

#include <QDebug>

KoreanPlugin::KoreanPlugin(QObject *parent) :
    AbstractLanguagePlugin(parent)
  , m_koreanLanguageFeatures(new KoreanLanguageFeatures)
  , m_processingWord(false)
{
#if 0
    connect(m_anthyAdapter, SIGNAL(newPredictionSuggestions(QString, QStringList)), this, SLOT(finishedProcessing(QString, QStringList)));
    connect(this, SIGNAL(parsePredictionText(QString)), m_anthyAdapter, SLOT(parse(const QString&)));
    connect(this, SIGNAL(candidateSelected(QString)), m_anthyAdapter, SLOT(wordCandidateSelected(const QString&)));
#endif
}

KoreanPlugin::~KoreanPlugin()
{
 
}

AbstractLanguageFeatures* KoreanPlugin::languageFeature()
{
    return m_koreanLanguageFeatures;
}

void KoreanPlugin::predict(const QString& surroundingLeft, const QString& preedit)
{
    Q_UNUSED(surroundingLeft)

    m_nextWord = preedit;
    if (!m_processingWord) {
        m_processingWord = true;
        Q_EMIT parsePredictionText(preedit);
    }
}

void KoreanPlugin::wordCandidateSelected(QString word)
{
    Q_EMIT candidateSelected(word);
}
#if 0
void KoreanPlugin::finishedProcessing(QString word, QStringList suggestions)
{
    Q_EMIT newPredictionSuggestions(word, suggestions);
    if (word != m_nextWord) {
        Q_EMIT parsePredictionText(m_nextWord);
    } else {
        m_processingWord = false;
    }
}
#endif
