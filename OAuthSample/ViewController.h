//
//  ViewController.h
//  OAuthSample
//
//  Created by Osmon, Cindy on 8/27/15.
//  Copyright (c) 2015 Osmon, Cindy. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IntuitWearKit/IWOAuthResponder.h>

@interface ViewController : UIViewController <IWOAuthResponder>

@property (weak, nonatomic) IBOutlet UIButton *oauthBtn;

//- (IBAction)authBtnAction:(id)sender;
- (IBAction)authBtnAction:(id)sender;

@end

