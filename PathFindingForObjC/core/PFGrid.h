//
//  FGrid.h
//
//  Created by JasioWoo on 14/10/27.
//  Copyright (c) 2014年 JasioWoo. All rights reserved.
//

#import "PFNode.h"


/**
 * The Grid class, which serves as the encapsulation of the layout of the nodes.
 */
@interface PFGrid : NSObject

/// The number of columns of the grid.
@property (nonatomic) unsigned int column;
/// The number of rows of the grid.
@property (nonatomic) unsigned int row;

/// A 2D array of int. 0-1(representing the walkable status of the nodes(0 for walkable))
@property (nonatomic) int **matrix;
/// A 2D array of nodes.
@property (nonatomic, retain, readonly) NSArray *nodes;


- (instancetype) initWithColumn:(unsigned int)col andRow:(unsigned int)row andBlockPoints:(NSArray*)blockPoints;


- (PFNode *)getNodeAtX:(int)x andY:(int)y;

/**
 * Determine whether the position is inside the grid.
 * XXX: `grid.isInside(x, y)` is wierd to read.
 * It should be `(x, y) is inside grid`, but I failed to find a better
 * name for this method.
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
- (BOOL)isInsideX:(int)x andY:(int)y;

/**
 * Determine whether the node at the given position is walkable.
 * (Also returns false if the position is outside the grid.)
 * @param {number} x - The x coordinate of the node.
 * @param {number} y - The y coordinate of the node.
 * @return {boolean} - The walkability of the node.
 */
- (BOOL)isWalkableAtX:(int)x andY:(int)y;

/**
 * Set whether the node on the given position is walkable.
 * NOTE: throws exception if the coordinate is not inside the grid.
 * @param {number} x - The x coordinate of the node.
 * @param {number} y - The y coordinate of the node.
 * @param {boolean} walkable - Whether the position is walkable.
 */
- (void)setWalkableAtX:(int)x andY:(int)y andWalkable:(BOOL)walkable;

/**
 * Get the neighbors of the given node.
 *
 *     offsets      diagonalOffsets:
 *  +---+---+---+    +---+---+---+
 *  |   | 0 |   |    | 0 |   | 1 |
 *  +---+---+---+    +---+---+---+
 *  | 3 |   | 1 |    |   |   |   |
 *  +---+---+---+    +---+---+---+
 *  |   | 2 |   |    | 3 |   | 2 |
 *  +---+---+---+    +---+---+---+
 *
 *  When allowDiagonal is true, if offsets[i] is valid, then
 *  diagonalOffsets[i] and
 *  diagonalOffsets[(i + 1) % 4] is valid.
 * @param {Node} node
 * @param {boolean} allowDiagonal
 * @param {boolean} dontCrossCorners
 */
- (NSArray *)getNeighborsWith:(PFNode*)node isAllowDiagonal:(BOOL)allowDiagonal isCrossCorners:(BOOL)dontCrossCorners;


// test
- (void)printFoundPath:(NSArray *)path;


@end
