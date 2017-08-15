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

#include "groupinvitewidget.h"

#include "src/friendlist.h"
#include "src/model/friend.h"
#include "src/persistence/settings.h"
#include "src/widget/tool/croppinglabel.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QSignalMapper>

static const QString INVITE_INFO_MESSAGE = GroupInviteWidget::tr("Invited by %1 on %2 at %3.");

/**
 * @class GroupInviteWidget
 *
 * @brief This class shows information about single group invite
 * and provides buttons to accept/reject it
 */

GroupInviteWidget::GroupInviteWidget(QWidget* parent, const GroupInvite& invite)
    : QWidget(parent)
    , acceptButton(new QPushButton(this))
    , rejectButton(new QPushButton(this))
    , inviteMessageLabel(new CroppingLabel(this))
    , widgetLayout(new QHBoxLayout(this))
    , inviteInfo(invite)
{
    connect(acceptButton, &QPushButton::clicked, [=]() { emit accepted(inviteInfo); });
    connect(rejectButton, &QPushButton::clicked, [=]() { emit rejected(inviteInfo); });
    widgetLayout->addWidget(inviteMessageLabel);
    widgetLayout->addWidget(acceptButton);
    widgetLayout->addWidget(rejectButton);
    setLayout(widgetLayout);
    retranslateUi();
}

/**
 * @brief Retranslate all elements in the form.
 */
void GroupInviteWidget::retranslateUi()
{
    const Friend* f = FriendList::findFriend(inviteInfo.getFriendId());
    const QString name = f->getDisplayedName().toHtmlEscaped();
    const QDateTime inviteDate = inviteInfo.getInviteDate();
    const Settings& s = Settings::getInstance();
    const QString date = inviteDate.toString(s.getDateFormat());
    const QString time = inviteDate.toString(s.getTimestampFormat());

    inviteMessageLabel->setText(INVITE_INFO_MESSAGE.arg("<b>%1</b>").arg(name, date, time));
    acceptButton->setText(tr("Join"));
    rejectButton->setText(tr("Decline"));
}

/**
 * @brief Returns infomation about invitation - e.g., who and when sent
 * @return Invite information object
 */
const GroupInvite GroupInviteWidget::getInviteInfo() const
{
    return inviteInfo;
}
