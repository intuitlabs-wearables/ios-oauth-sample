 //
//  UIAlertController+NSError.h
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
#import <UIKit/UIKit.h>

/*!
 * @class UIAlertController
 *
 * @discussion Catergory that extends UIAlertController to handle Alerts
 *             that display information from NSError objects.
 */
@interface UIAlertController (NSErrorAddition)

/*!
 * @discussion Static method for displaying Alert Message with the contents
 *             of the NSError object provided as input.
 * @param NSError object containing the Alert message content
 * @param NSString representing the Title to display in the Alert Dialog
 * @return generic instancetype of UIAlertController
 */
+(instancetype)alertControllerWithError:(NSError *)error title: (NSString *)title;
@end
