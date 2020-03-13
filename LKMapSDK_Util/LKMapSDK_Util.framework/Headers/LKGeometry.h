//
//  LKGeometry.h
//  LKMapSDK_Util
//
//  Created by hao on 2019/12/18.
//  Copyright © 2019 luokung. All rights reserved.
//

#import <LKMapSDK_Base/LKMapSDK_Base.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#pragma mark 坐标转换
/**
 经纬度转换
 输入输出为其他类型时，坐标不作转换
 
 @param coordinate 待转换的原始经纬度
 @param fromType 原始经纬度类型
 @param toType 目标的经纬度类型
 @return 转换后的经纬度
 */
UIKIT_EXTERN CLLocationCoordinate2D LKCoordTrans(CLLocationCoordinate2D coordinate, LKCoordType fromType, LKCoordType toType);

#pragma mark 面积计算

/**
 * 获取矩形区域的面积
 *
 * @param bounds 地理矩形区域
 * @return 区域面积，单位：平方米
 */
UIKIT_EXTERN double LKAreaWithCoordinateBounds(LKCoordinateBounds bounds);

#pragma mark 距离计算

/**
 * 获取地理坐标到线段的最短距离
 *
 * @param aCoor 地理坐标
 * @param startSegmentCoor 线段的起点地理坐标
 * @param endSegmentCoor 线段的终点地理坐标
 * @return 距离，单位：米
 */
UIKIT_EXTERN CLLocationDistance LKDistanceFromCoordinateToLineSegment(CLLocationCoordinate2D aCoor, CLLocationCoordinate2D startSegmentCoor, CLLocationCoordinate2D endSegmentCoor);

/**
 * 获取两个地理坐标之间的距离
 *
 * @param coor1 地理坐标1
 * @param coor2 地理坐标2
 * @return 距离，单位：米
 */
UIKIT_EXTERN CLLocationDistance LKDistanceBetweenCoordinates(CLLocationCoordinate2D coor1, CLLocationCoordinate2D coor2);

/**
 * 获取地理坐标到线段的垂足
 *
 * @param aCoor 地理坐标
 * @param startSegmentCoor 线段的起点地理坐标
 * @param endSegmentCoor 线段的终点地理坐标
 * @return 垂足地理坐标
 */
UIKIT_EXTERN CLLocationCoordinate2D LKPedalFromCoordinateToLineSegment(CLLocationCoordinate2D aCoor, CLLocationCoordinate2D startSegmentCoor, CLLocationCoordinate2D endSegmentCoor);

/**
 * 获取地理坐标到折线距离最近的点
 *
 * @param aCoor 地理坐标
 * @param polyline 折线地理坐标数组
 * @param count 地理坐标数量
 * @return 折线上最近的地理坐标点
 */
UIKIT_EXTERN CLLocationCoordinate2D LKNearestCoordinateFromPolyline(CLLocationCoordinate2D aCoor, CLLocationCoordinate2D *polyline, NSUInteger count);


#pragma mark 判断空间位置
/**
 * 判断地理坐标是否在多边形内
 *
 * @param aCoor 地理坐标
 * @param polygon 多边形的顶点数组
 * @param count 目标多边形顶点数组元素个数
 * @return YES是，NO否
 */
UIKIT_EXTERN BOOL LKPolygonContainsCoordinate(CLLocationCoordinate2D aCoor, CLLocationCoordinate2D *polygon, NSUInteger count);

/**
 * 判断地理坐标是否在圆内
 *
 * @param aCoor 地理坐标
 * @param center 圆的中心点地理坐标
 * @param radius 圆的半径，单位：米
 * @return YES是，NO否
 */
UIKIT_EXTERN BOOL LKCircleContainsCoordinate(CLLocationCoordinate2D aCoor, CLLocationCoordinate2D center, CLLocationDistance radius);

/**
 * 判断地理坐标是否在线段上
 *
 * @param aCoor 地理坐标
 * @param startSegmentCoor 线段的起点地理坐标
 * @param endSegmentCoor 线段的终点地理坐标
 * @return YES是，NO否
 */
UIKIT_EXTERN BOOL LKLineSegmentContainsCoordinate(CLLocationCoordinate2D aCoor, CLLocationCoordinate2D startSegmentCoor, CLLocationCoordinate2D endSegmentCoor);

/// 工具类
@interface LKGeometry : NSObject
@end

