//
//  IWOAuthResponder.h
//  IWOAuth
//
// Copyright (c) 2015 Intuit Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/*!
 * @protocol IWOAuthResponder
 *
 * @discussion This protocol represents the communication between the IWOAuthManager
 *             and a deleget/consumer.  It handles the communication of the authorization
 *             status from the IWOAuthManager to the delegate.
 */
@protocol IWOAuthResponder <NSObject>

/*!
 * @discussion This method will be called by IWOAuthManager after the OAuth flow has
 *             completed successfully.
 * @param The userEmail address will be passed from IWOAuthManager to this method so
 *        that this can be used as a unique key to register with the Push Notification
 *        Gateway.
 */
- (void)authorizationSuccessful:(NSString *)userEmail;

/*!
 * @discussion This method will be called by IWOAuthManager if the OAuth flow has
 *             canceled by the user.  If the OAuth flow is canceled, it means that
 *             we have not completed the OAuth flow and are therefore not able to 
 *             access the user's data.
 */
- (void)authorizationCanceled;

/*!
 * @discussion This method will be called by IWOAuthManager when the OAuth flow has
 *             failed with some error condition.
 * @param The NSError object that contains a description of the error condition.
 */
- (void)authorizationFailedWithError:(NSError *)error;

@end
