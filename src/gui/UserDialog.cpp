/*

                          Firewall Builder

                 Copyright (C) 2008 NetCitadel, LLC

  Author:  alek@codeminders.com

  $Id$

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#include "../../config.h"
#include "global.h"
#include "utils.h"

#include "FWBTree.h"
#include "UserDialog.h"

#include "ProjectPanel.h"
#include "fwbuilder/Library.h"
#include "fwbuilder/UserService.h"
#include "fwbuilder/Interface.h"
#include "fwbuilder/FWException.h"

#include <qlineedit.h>
#include <qspinbox.h>
#include <qcheckbox.h>
#include <qtextedit.h>
#include <qcombobox.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include "FWBSettings.h"

#include "FWWindow.h"
using namespace std;
using namespace libfwbuilder;

UserDialog::UserDialog(ProjectPanel *project, QWidget *parent) : QWidget(parent), m_project(project)
{
    m_dialog = new Ui::UserDialog_q;
    m_dialog->setupUi(this);
    obj=NULL;
}

UserDialog::~UserDialog() { delete m_dialog; }

void UserDialog::getHelpName(QString *str)
{
    *str = "UserDialog";
}

void UserDialog::loadFWObject(FWObject *o)
{
    obj=o;
    UserService *s = dynamic_cast<UserService*>(obj);
    assert(s!=NULL);
    
    init=true;

    m_dialog->obj_name->setText( QString::fromUtf8(s->getName().c_str()) );
    m_dialog->userid->setText( s->getUserId().c_str() );
    m_dialog->comment->setText( QString::fromUtf8(s->getComment().c_str()) );

    //apply->setEnabled( false );

    m_dialog->obj_name->setEnabled(!o->isReadOnly());
    setDisabledPalette(m_dialog->obj_name);

    m_dialog->userid->setEnabled(!o->isReadOnly());
    setDisabledPalette(m_dialog->userid);

    m_dialog->comment->setReadOnly(o->isReadOnly());
    setDisabledPalette(m_dialog->comment);


    init=false;
}

void UserDialog::changed()
{
    //apply->setEnabled( true );
    emit changed_sign();
}

void UserDialog::validate(bool *res)
{
    *res=true;

    if (!isTreeReadWrite(this,obj)) { *res=false; return; }
    if (!validateName(this,obj,m_dialog->obj_name->text())) { *res=false; return; }

    UserService *s = dynamic_cast<UserService*>(obj);
    assert(s!=NULL);
}

void UserDialog::isChanged(bool*)
{
    //*res=(!init && apply->isEnabled());
}

void UserDialog::libChanged()
{
    changed();
}

void UserDialog::applyChanges()
{
    UserService *s = dynamic_cast<UserService*>(obj);
    assert(s!=NULL);

    string oldname=obj->getName();
    s->setName( string(m_dialog->obj_name->text().toUtf8().constData()) );
    s->setComment( string(m_dialog->comment->toPlainText().toUtf8().constData()) );
    s->setUserId( string(m_dialog->userid->text().toUtf8().constData()) );

    m_project->updateObjName(obj,QString::fromUtf8(oldname.c_str()));

    emit notify_changes_applied_sign();
}

void UserDialog::discardChanges()
{
    loadFWObject(obj);
}


/* ObjectEditor class connects its slot to this signal and does all
 * the verification for us, then accepts (or not) the event. So we do
 * nothing here and defer all the processing to ObjectEditor
 */
void UserDialog::closeEvent(QCloseEvent *e)
{
    emit close_sign(e);

}

