//
//  MKReverseGeocoder.h
//  MapKit
//
//  Created by Rick Fillion on 7/24/10.
//  Copyright 2010 Centrix.ca. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <MapKit/MKTypes.h>

@class MKPlacemark, MKWebView;
@protocol MKReverseGeocoderDelegate;

@interface MKReverseGeocoder : NSObject {
    CLLocationCoordinate2D coordinate;
    MKPlacemark *placemark;
    BOOL querying;
@private
    MKWebView *webView;
    BOOL webViewLoaded;
}

- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate;


// A MKReverseGeocoder object should only be started once.
- (void)start;
- (void)cancel;

@property (nonatomic, weak) id<MKReverseGeocoderDelegate> delegate;
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;      // the exact coordinate being reverse geocoded.
@property (nonatomic, readonly) MKPlacemark *placemark;
@property (nonatomic, readonly, getter=isQuerying) BOOL querying;

@end

@protocol MKReverseGeocoderDelegate <NSObject>
@required
- (void)reverseGeocoder:(MKReverseGeocoder *)geocoder didFindPlacemark:(MKPlacemark *)placemark;
// There are at least two types of errors:
//   - Errors sent up from the underlying connection (temporary condition)
//   - Result not found errors (permanent condition).  The result not found errors
//     will have the domain MKErrorDomain and the code MKErrorPlacemarkNotFound
- (void)reverseGeocoder:(MKReverseGeocoder *)geocoder didFailWithError:(NSError *)error;
@end
