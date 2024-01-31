#import <react-native-live-markdown/BlockquoteLayoutFragment.h>

@implementation BlockquoteLayoutFragment

- (void)drawAtPoint:(CGPoint)point
          inContext:(CGContextRef)context
{
  CGContextSaveGState(context);

  CGRect fragmentTextBounds = CGRectNull;
  for (NSTextLineFragment *lineFragment in self.textLineFragments) {
    CGRect lineFragmentBounds = [lineFragment typographicBounds];
    if (CGRectIsNull(fragmentTextBounds)) {
      fragmentTextBounds = lineFragmentBounds;
    } else {
      fragmentTextBounds = CGRectUnion(fragmentTextBounds, lineFragmentBounds);
    }
  }

  fragmentTextBounds.size.width = 5;

  CGContextSetFillColorWithColor(context, [[UIColor redColor] CGColor]);
  CGContextFillRect(context, fragmentTextBounds);

  CGContextRestoreGState(context);

  [super drawAtPoint:point inContext:context];
}

@end
