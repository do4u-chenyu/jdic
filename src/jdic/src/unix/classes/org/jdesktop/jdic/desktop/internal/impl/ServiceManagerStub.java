/*
 * Copyright (C) 2004 Sun Microsystems, Inc. All rights reserved. Use is
 * subject to license terms.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA.
 */ 

package org.jdesktop.jdic.desktop.internal.impl;

import org.jdesktop.jdic.desktop.internal.ServiceManager;


/**
 * The <code>ServiceManagerStub</code> class implements the particular
 * lookup of services. The request in ServiceManager to lookup services is 
 * delegated to this object.
 * 
 * @see org.jdesktop.jdic.desktop.internal.ServiceManager
 */
public class ServiceManagerStub {

    /**
     * Suppress default constructor for noninstantiability.
     */
    private ServiceManagerStub() {}
  
    /**
     * Gets the requested service object according to the given service name.
     * 
     * @param serviceName the given service name.
     * @throws IllegalArgumentException if there is no approprate service according
     *         to the given service name, or UnsupportedOperationException if we've 
     *         got unsupported system mailer.
     * @throws UnsupportedOperationException if the current mailer is not supported
     *         for this operation.
     * @return the requested service object.
     */
    public static Object getService(String serviceName) 
        throws IllegalArgumentException, UnsupportedOperationException {
        if (serviceName.equals(ServiceManager.LAUNCH_SERVICE)) {
            return new GnomeLaunchService();
        } else if (serviceName.equals(ServiceManager.BROWSER_SERVICE)) {
            return new GnomeBrowserService();
        } else if (serviceName.equals(ServiceManager.MAILER_SERVICE)) {
            // Get default mailer path. 
            String defMailerPath = GnomeUtility.getDefaultMailerPath();

            if (defMailerPath.indexOf(DesktopConstants.EVO_MAILER) != -1) { 
                return new GnomeEvoMailer(defMailerPath.trim());
            } else if (defMailerPath.indexOf(DesktopConstants.MOZ_MAILER) != -1 
                       ||defMailerPath.indexOf(DesktopConstants.THBD_MAILER) != -1) { 
                return new GnomeMozMailer(defMailerPath.trim());
            } else {
                throw new UnsupportedOperationException("Current system default mailer is not supported.");
            }
        } else {
            // Should never arrive here. 
            throw new IllegalArgumentException("The requested service is not supported.");
        }
    }
}
