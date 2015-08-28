//
//  IWOAuthRecord.h
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
 * @class IWOAuthRecord
 *
 * @discussion IWOAuthRecord keeps track of information necessary for the IWOAuthManager
 *             such as the AppCenter OAuth URL to load and the alert message
 *             to display to ask user if they give permission to get access
 *             to their data.
 */
@interface IWOAuthRecord : NSObject

/*!
 * @discussion the AppCenter OAuth URL to load.
 */
@property NSString *url;

/*!
 * @discussion The alert message to display to ask user if they give permission 
 *             to get access to their data.
 */
@property NSString *alertMessage;

/*!
 * @discussion Initization method for creating the IWOAuthRecord object given
 *             the AppCenter OAuth URL to load and the alert message
 *             to display to ask user if they give permission to get access
 *             to their data.
 * @param NSString representing the AppCenter OAuth URL to load.
 * @param NSString representing the alert message to display to ask user
 *         if they give permission to get access to their data.
 * @return Generic pointer to newly created IWOAuthRecord object.
 */
- (id)initWithOAuthData: (NSString *)oauthUrl  alertMessage:(NSString *)message;
@end
