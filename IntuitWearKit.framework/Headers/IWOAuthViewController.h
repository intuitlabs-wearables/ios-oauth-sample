//
//  IWOAuthViewController.h
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
#import <UIKit/UIKit.h>
#import <IntuitWearKit/IWOAuthManager.h>

/*!
 * @class IWOAuthViewController
 *
 * @discussion This class is a UIViewController which encompasses a WebView that
 *             is used to display the AppCenter OAuth flow web screens that walk the
 *             user through the process of granting permission to access their data.
 *             It also acts as a UIWebViewDelegate to track WebView errors and status
 *             updating so that it can show busy cursors as pages are loading and trap
 *             when the web flow is done by looking for the unique URL starting with:
 *             intuitwear://
 */
@interface IWOAuthViewController : UIViewController<UIWebViewDelegate>

/*!
 * @discussion WebView displaying OAuth flow that grants the application access to 
 *             the users data.
 */
@property (strong, nonatomic) UIWebView *webView;

/*!
 * @discussion Activity Indicator displayed while web pages are busy loading during
 *             OAuth flow.
 */
@property (strong, nonatomic) UIActivityIndicatorView *actIndicator;

/*!
 * @discussion Pointer to the ViewController owner of this controller. This delegate
 *             must implement the IWOAuthResponder protocol.
 */
@property (strong, nonatomic) IWOAuthManager *delegate;

/*!
 * @discussion Initialization method that initializes the IWOAuthViewController with
 *             the AppCenter OAuth URL to load in the containing WebView.
 * @param NSString representing the AppCenter OAuth URL to load in the WebView.
 * @return Generic id pointer to this IWOAuthViewController object.
 */
- (id)initWithUrl: (NSString *)oauthUrl;

@end
