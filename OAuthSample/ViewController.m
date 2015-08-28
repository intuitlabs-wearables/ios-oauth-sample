//
//  ViewController.m
//  OAuthSample
//
//  Created by Osmon, Cindy on 8/27/15.
//  Copyright (c) 2015 Osmon, Cindy. All rights reserved.
//

#import "ViewController.h"
#import <IntuitWearKit/IWOAuthManager.h>
#import <IntuitWearKit/UIAlertController+NSError.h>

#define APPCENTER_AUTHORIZED_KEY		@"appcenterauthorizedbject"

@interface ViewController () {
    // Pointer to IWOAuthManager to handle all OAuth interactions.
    IWOAuthManager *oauthMgr;
}

@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    // Check if user has already authenticated the Application to access their data.
    // Must do this after viewDidLoad so window is valid.
    if ( ![self isAppCenterAuthenticated]) {
        [self doAuthentication];
    }
}

//
// Create the IWOAuthManager object that handles displaying a dialog
// asking the user to grant permission to access their data and
// then displays the AppCenter OAuth flow screens to walk them through
// the authorization process.
//
- (void)doAuthentication {
    oauthMgr = [[IWOAuthManager alloc] initWithDelegateAndOAuthData:self oauthUrl:@"https://appcenter.intuit.com/b7qsn5mjg2/subscribe" alertMessage:NSLocalizedString(@"This application would like to connect to your QBO Data.", nil)];
    [oauthMgr authenticateConnections];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//
// This action is called when the user selects the Reset button.
// It is for testing only and is used to reset the state of the
// application back to its initial 'unauthorized' state.
//
- (IBAction)authBtnAction:(id)sender {
    NSLog(@">>>>> Reset Button called");
    [self saveAuthorizationFlag:NO];
    [self doAuthentication];
}

//
// Checks the NSUserDefaults value, APPCENTER_AUTHORIZED_KEY, to
// see if the user has already given authorization to access
// their data as we only want to ask this once.
//
- (BOOL)isAppCenterAuthenticated {
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    BOOL isAuthorized = [prefs boolForKey:APPCENTER_AUTHORIZED_KEY];
    return isAuthorized;
}

//
// Convenience method for saving the authorization state to
// NSUserDefaults.
//
- (void)saveAuthorizationFlag:(BOOL)isAuthorized {
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    [prefs setBool:isAuthorized forKey:APPCENTER_AUTHORIZED_KEY];
    [prefs synchronize];
}

#pragma - IWOAuthResponder Protocol Methods

//
// This IWOAuthResponder protocol method is called by the IntuitWear SDK
// when the AppCenter OAuth flow has returned successfully and access to
// the users data has been granted.
- (void)authorizationSuccessful:(NSString *)userEmail {
    NSLog(@"ViewController :: respondToAuthorization called!! User email = %@", userEmail);
    
    // Save authentication flag as YES for next login to consult so we know
    // we have already been granted access to the user's data.
    [self saveAuthorizationFlag:YES];
    
    // Create NSError object for Alert to let the user know
    // that the Authorization was successful.
    NSDictionary *userInfo = @{
                               NSLocalizedDescriptionKey: NSLocalizedString(@"", nil),
                               NSLocalizedFailureReasonErrorKey: NSLocalizedString(@"", nil)
                               };
    NSError *error = [NSError errorWithDomain:@"IWOAuthDomain"
                                         code:-1001
                                     userInfo:userInfo];
    UIAlertController *alert = [UIAlertController alertControllerWithError:error title:NSLocalizedString(@"Authorization Successful", nil)];
    [self presentViewController:alert animated:YES completion:nil];
    
    // Now, here we could enable Push Notifications using the userEmail
    // value as the unique key to PNG.
    
    ////////////////////////////////////////////////////////////////////
    //
    // REGISTER FOR PUSH NOTIFICATIONS HERE...
}

//
// This IWOAuthResponder protocol method is called by the IntuitWear SDK
// when the user has canceled from the Dialog asking him/her if
// they would like to grant the app access to their data.
//
- (void)authorizationCanceled {
    NSLog(@"ViewController :: authorizationCanceled called!!");
    
    // Create NSError object for Alert upon Cancelation
    NSDictionary *userInfo = @{
                               NSLocalizedDescriptionKey: NSLocalizedString(@"The application is NOT authorized to access your data.", nil),
                               NSLocalizedFailureReasonErrorKey: NSLocalizedString(@"", nil)
                               };
    NSError *error = [NSError errorWithDomain:@"IWOAuthDomain"
                                         code:-1001
                                     userInfo:userInfo];
    UIAlertController *alert = [UIAlertController alertControllerWithError:error title:NSLocalizedString(@"Authorization Canceled", nil)];
    [self presentViewController:alert animated:YES completion:nil];
}

//
// This IWOAuthResponder protocol method is called by the IntuitWear SDK
// when the AppCenter OAuth flow has some sort of error (usually caused
// by an http access error).
// This method will display an Alert Dialog with the content of the error
// message.
//
- (void)authorizationFailedWithError:(NSError *)error {
    NSLog(@"ViewController :: authorizationFailedWithError called!! Error = %@", [error description]);
    
    UIAlertController *alert = [UIAlertController alertControllerWithError:error title:NSLocalizedString(@"Authorization Error", nil)];
    [self presentViewController:alert animated:YES completion:nil];
}

@end
