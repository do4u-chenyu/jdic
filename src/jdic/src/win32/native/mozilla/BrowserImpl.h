/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org Code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 2001
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Chak Nanga <chak@netscape.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef _BROWSERIMPL_H
#define _BROWSERIMPL_H

#include "BrowserFrm.h"
#include "nsIWebBrowserChromeFocus.h"
#include "nsIURIContentListener.h"
#include "nsICommandParams.h"
#include "nsPIDOMWindow.h"
#include "nsIContent.h"
#include "nsIChromeEventHandler.h"
#include "nsIDOMWindow.h"
#include "nsIDOMWindowInternal.h"
#include "nsIDOMEventReceiver.h"
#include "nsIDOMKeyListener.h"
#include "nsIDOMKeyEvent.h"
#include "nsIDOMEventReceiver.h"

class CBrowserImpl : public nsIInterfaceRequestor,
                     public nsIWebBrowserChrome,
                     public nsIWebBrowserChromeFocus,
                     public nsIEmbeddingSiteWindow2,
                     public nsIWebProgressListener,
                     public nsIURIContentListener,
                     public nsIContextMenuListener2,
                     public nsITooltipListener,
                     public nsIDOMKeyListener,
                     public nsSupportsWeakReference
{
public:
    CBrowserImpl();
    ~CBrowserImpl();
    NS_METHOD Init(CBrowserFrame* pBrowserFrameGlue,
                   nsIWebBrowser* aWebBrowser);
                   
	nsresult InitKeyListener(nsIDOMEventReceiver *aEventReceiver);
    nsresult GetPrivateDOMWindow (nsPIDOMWindow** outPIDOMWindow);
	nsresult GetEventReceiver (nsIDOMEventReceiver** outEventRcvr);
	nsresult RegristerKeyEvent();
	// nsIDOMEventListener
	NS_DECL_NSIDOMEVENTLISTENER
	// nsIDOMKeyListener
	NS_IMETHOD KeyDown(nsIDOMEvent* aDOMEvent);
	NS_IMETHOD KeyUp(nsIDOMEvent* aDOMEvent);
	NS_IMETHOD KeyPress(nsIDOMEvent* aDOMEvent);
	
    NS_DECL_ISUPPORTS
    NS_DECL_NSIINTERFACEREQUESTOR
    NS_DECL_NSIWEBBROWSERCHROME
    NS_DECL_NSIWEBBROWSERCHROMEFOCUS
    NS_DECL_NSIEMBEDDINGSITEWINDOW
    NS_DECL_NSIEMBEDDINGSITEWINDOW2
    NS_DECL_NSIWEBPROGRESSLISTENER
    NS_DECL_NSIURICONTENTLISTENER
    NS_DECL_NSICONTEXTMENULISTENER2
    NS_DECL_NSITOOLTIPLISTENER

protected:

    CBrowserFrame  *m_pBrowserFrame;
    nsCOMPtr<nsIWebBrowser> mWebBrowser;
    PRBool mIsModal;

    friend class MozEmbedApp;
};

#endif //_BROWSERIMPL_H
