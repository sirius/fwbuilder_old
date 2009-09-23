/* 

                          Firewall Builder

                 Copyright (C) 2009 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@vk.crocodile.org

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

#ifndef __LINUX24IFACEOPTSDIALOG_H_
#define __LINUX24IFACEOPTSDIALOG_H_

#include <ui_linux24ifaceoptsdialog_q.h>
#include "DialogData.h"

#include <QDialog>

namespace libfwbuilder
{
    class FWObject;
};

class linux24IfaceOptsDialog : public QDialog
{
    Q_OBJECT

public:
    linux24IfaceOptsDialog(QWidget *parent, libfwbuilder::FWObject *o);
    ~linux24IfaceOptsDialog();

private:
    libfwbuilder::FWObject *obj;
    DialogData data;
    Ui::linux24IfaceOptsDialog_q *m_dialog;
    bool cluster_interface;

    /** validate user input for different interface types */
    bool validate();

protected slots:
    virtual void accept();
    virtual void reject();
    virtual void help();
    void typeChanged(const QString&);
    void bondingPolicyChanged(const QString&);
};

#endif // __LINUX24IFACEOPTSDIALOG_H_

