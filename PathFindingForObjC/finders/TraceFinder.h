//
//  TraceFinder.h
//  PathFindingForObjC-Example
//
//  Created by JasioWoo on 14/11/1.
//  Copyright (c) 2014年 JasioWoo. All rights reserved.
//

#import "BaseFinder.h"

/**
 * A* path-finder.
 * based upon https://github.com/bgrins/javascript-astar
 * @constructor
 * @param {object} opt
 * @param {boolean} opt.allowDiagonal Whether diagonal movement is allowed.
 * @param {boolean} opt.allowCrossCorners Disallow diagonal movement touching block corners.
 * @param {function} opt.heuristic Heuristic function to estimate the distance
 *     (defaults to manhattan).
 * @param {integer} opt.weight Weight to apply to the heuristic to allow for suboptimal paths,
 *     in order to speed up the search.
 */
@interface TraceFinder : BaseFinder

@end
