/*
 * Copyright 2015 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "koreanlanguagefeatures.h"

KoreanLanguageFeatures::KoreanLanguageFeatures(QObject *parent) :
    QObject(parent)
{
}

KoreanLanguageFeatures::~KoreanLanguageFeatures()
{
}

bool KoreanLanguageFeatures::alwaysShowSuggestions() const
{
    // Korean characters can only be entered via suggestions.
    return true;
}

bool KoreanLanguageFeatures::autoCapsAvailable() const
{
    return false;
}

bool KoreanLanguageFeatures::activateAutoCaps(const QString &preedit) const
{
    Q_UNUSED(preedit)
    return false;
}

QString KoreanLanguageFeatures::appendixForReplacedPreedit(const QString &preedit) const
{
    Q_UNUSED(preedit)
    // auto add a character in any event?
    return QString("");
}

bool KoreanLanguageFeatures::isSeparator(const QString &text) const
{
    static const QString separators = QString::fromUtf8("。、,!?:;.\r\n");

    if (text.isEmpty()) {
        return false;
    }

    if (separators.contains(text.right(1))) {
        return true;
    }

    return false;
}

bool KoreanLanguageFeatures::isSymbol(const QString &text) const
{
    Q_UNUSED(text)

    return false;
}

bool KoreanLanguageFeatures::ignoreSimilarity() const
{
    return true;
}

bool KoreanLanguageFeatures::wordEngineAvailable() const
{
    return true;
}

bool KoreanLanguageFeatures::enablePreeditAtInsertion() const
{
    return true;
}

bool KoreanLanguageFeatures::restorePreedit() const
{
    return false;
}
