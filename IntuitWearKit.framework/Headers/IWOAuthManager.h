//
//  IWOAuthManager.h
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
#import <IntuitWearKit/IWOAuthResponder.h>
#import <IntuitWearKit/IWOAuthRecord.h>

/*!
 * @class IWOAuthManager
 *
 * @discussion Manages the WebView flow screens for authentication.  Displays the OAuth screens in a web view and handles error conditions, cancelations and authorization success by calling the parent view controller as its delegate.  The Parent ViewController must implement the IWOAuthResponder protocol.
 */
@interface IWOAuthManager : NSObject<IWOAuthResponder>

/*!
 * @discussion IWOAuthRecord object that holds the OAuth URL string and the 
 *             message to be displayed on a Dialog.
 */
@property (nonatomic, strong)IWOAuthRecord *_record;

/*!
 * @discussion Initializes IWOAuthManager with the OAuth URL, alert message and 
 *             a pointer to the parent ViewController (which must implement 
 *             IWOAuthResponder).
 * @param The Parent ViewController (which must implement
 *             IWOAuthResponder)
 * @param NSString representing the OAuth URL
 * @param NSString representing the message to be displayed on an Alert Message
 *        prompting user to authenticate their application.
 * @return Returns generic pointer to IWOAuthManager class
 */
- (id)initWithDelegateAndOAuthData: (id<IWOAuthResponder>)delegate oauthUrl:(NSString *)oauthUrl alertMessage:(NSString *)message;

/*!
 * @discussion Begins the process of authenticating to the users data by first displaying
 *             an Alert Dialog asking the user to grant access to their data.  Handles the
 *             situation if the user cancels out of the Alert by calling the delegate's
 *             protocol methods.  If the user grants permission, this method continues on
 *             by displaying the OAuth URL in a WebView and allows the user to go through
 *             the OAuth flow.
 */
- (void)authenticateConnections;

@end
