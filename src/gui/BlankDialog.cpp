/*

                          Firewall Builder

                 Copyright (C) 2006 NetCitadel, LLC

  Author:  Illiya Yalovoy <yalovoy@gmail.com>

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

#include "BlankDialog.h"

using namespace std;
using namespace libfwbuilder;

BlankDialog::BlankDialog(QWidget *parent) : BaseObjectDialog(parent)
{
    m_dialog = new Ui::BlankDialog_q;
    m_dialog->setupUi(this);
    obj=NULL;
}

BlankDialog::~BlankDialog()
{
    delete m_dialog;
}

void BlankDialog::getHelpName(QString *str)
{
    *str = "BlankDialog";
}

void BlankDialog::loadFWObject(FWObject *o)
{
    obj = o;
}

void BlankDialog::validate(bool *res)
{
    *res = true;
}

void BlankDialog::applyChanges()
{
    BaseObjectDialog::applyChanges();
}

void BlankDialog::discardChanges()
{
    loadFWObject(obj);
}



