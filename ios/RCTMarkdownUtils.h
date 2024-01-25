#import <React/RCTBackedTextInputViewProtocol.h>
#import <react-native-live-markdown/RCTMarkdownStyle.h>

NS_ASSUME_NONNULL_BEGIN

@interface RCTMarkdownUtils : NSObject

@property (nonatomic) RCTMarkdownStyle *markdownStyle;
@property (nonatomic) NSMutableArray<NSValue *> *blockquoteRanges;
@property (weak, nonatomic) UIView<RCTBackedTextInputViewProtocol> *backedTextInputView;

- (instancetype)initWithBackedTextInputView:(UIView<RCTBackedTextInputViewProtocol> *)backedTextInputView;

- (NSAttributedString *)parseMarkdown:(nullable NSAttributedString *)input;

@end

extern RCTMarkdownUtils *globalMarkdownUtils;

NS_ASSUME_NONNULL_END
