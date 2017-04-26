/*
    Copyright © 2017 by The qTox Project Contributors

    This file is part of qTox, a Qt-based graphical interface for Tox.

    qTox is libre software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    qTox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with qTox.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "basechatmessagemodel.h"

#include "src/core/core.h"

/**
 * @class Base class for all chat message model classes
 */
BaseChatMessageModel::BaseChatMessageModel(const ToxPk& author, const QDateTime& dt, bool isSent)
    : author{author}
    , dateTime{dt}
    , isMessageSent{isSent}
    , isValidMessage{!author.isEmpty() && !dateTime.isNull()}
{
}

/**
 * @brief Shows that you are an author of message or not
 * @return True if you are an author, false otherwise
 */
bool BaseChatMessageModel::isSelf() const
{
    return author == Core::getInstance()->getSelfPublicKey();
}

/**
 * @brief Shows whether message was sent or not
 * @return True if message was sent, false otherwise
 */
bool BaseChatMessageModel::isSent() const
{
    return isMessageSent;
}

/**
 * @brief Shows whether chat message valid or not
 * @return True if author is not empty and datetime property is not null
 */
bool BaseChatMessageModel::isValid() const
{
    return isValidMessage;
}

/**
 * @brief Public key of message's author
 */
ToxPk BaseChatMessageModel::getAuthorPublicKey() const
{
    return author;
}

/**
 * @brief Date and time when message was sent
 */
QDateTime BaseChatMessageModel::getSendingDateTime() const
{
    return dateTime;
}
