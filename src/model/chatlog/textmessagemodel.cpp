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

#include "textmessagemodel.h"

/**
 * @brief ACTION_MESSAGE_PREFIX Prefix from which action text messages start
 */
static const QString ACTION_MESSAGE_PREFIX = "/me";

/**
 * @class Model for chat text messages
 */
TextMessageModel::TextMessageModel(const ToxPk& author,
                                   const QString& messageText,
                                   const QDateTime& dateTime,
                                   bool isSent)
    : BaseChatMessageModel(author, dateTime, isSent)
    , message{messageText}
{
    isValidMessage = isValidMessage && !message.isNull() && !message.isEmpty();
    isAction = message.startsWith(ACTION_MESSAGE_PREFIX);
    if (isAction) {
        message.remove(0, ACTION_MESSAGE_PREFIX.length());
    }
}

/**
 * @brief Shows that text message is an action message or not
 * @return True if it's an action message, false otherwise
 */
bool TextMessageModel::isActionMessage() const
{
    return isAction;
}

/**
 * @brief Message text
 */
QString TextMessageModel::getMessageText() const
{
    return message;
}
