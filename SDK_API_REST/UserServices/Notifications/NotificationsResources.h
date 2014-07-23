//
//  NotificationsResources.h
//
//  @version 1.0
//  @author Eder Gomez Nocelo, edegom.nocelo@gmail.com
//

// Copyright (c) 2013-2014 Hova Networks S.A.P.I. de C.V.
// Redistribution and use in any form, with or without modification,
// is strictly prohibited.

#import <Foundation/Foundation.h>
#import "Response.h"
#import "Notification.h"
#import "ClientPOST.h"
#import "ClientPUT.h"
#import "ClientGET.h"

@interface NotificationsResources : NSObject

/*! Creates a notification to have a standardized message that can be sent to different users without changing its contents, in this case the title and message. The required date are: title, message, broot. This parameters are in NotificationsParameters classs.
 *
 * \param NotificationsParameters object.
 *
 * \return a response instance with the http status code and the body decoded as NSDictionary
 *   is returned on given completion handler.
 */
+ (void) createNewNotification:(void (^)(Response *))block WithParameters:(Notification *) params;


/*!The update in the notification is to change the status from true to false and vice versa. The required data are:
 * notification_id, read
 *
 * \param NSStrign notification_id: Id assigned to the notification when it was registered.
 * \param NSStrign read: State of the notification, can be true or false.
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) updateNotification:(void (^)(Response *))block WithNotificationId:(NSString *) notifyId statusRead:(BOOL) read;


/*!You know the general information of all notifications registered. This resource has the next parameters: branch_id .
 *
 * \param NSString branch_id: branch id for the current user.
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) getAllNotifications:(void (^)(Response *))block WithBranchID:(NSString *) branch_id;


/*!View information about a specific notification of a user. This resource has the next parameters: branch_id, notification_id .
 *
 * \param NSString branch_id: branch id of the current user
 * \param NSString notification_id: notification id that you want to get
 *
 * \return a response instance with the http status code
 *   is returned on given completion handler.
 */
+ (void) getSpecificNotification:(void (^)(Response *))block WithBranchID:(NSString *) branch_id NotificationID:(NSString *) notifyID;


@end
