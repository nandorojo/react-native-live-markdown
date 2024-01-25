#pragma once

#include <react/renderer/components/RNLiveMarkdownSpec/EventEmitters.h>
#include <react/renderer/components/RNLiveMarkdownSpec/Props.h>
#include <react/renderer/components/RNLiveMarkdownSpec/States.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>
#include <react/renderer/core/LayoutContext.h>
#include <jsi/jsi.h>

namespace facebook {
namespace react {

JSI_EXPORT extern const char MarkdownTextInputDecoratorViewComponentName[];

class JSI_EXPORT MarkdownTextInputDecoratorViewShadowNode final : public ConcreteViewShadowNode<
    MarkdownTextInputDecoratorViewComponentName,
    MarkdownTextInputDecoratorViewProps,
    MarkdownTextInputDecoratorViewEventEmitter,
    MarkdownTextInputDecoratorViewState> {
 public:
  using ConcreteViewShadowNode::ConcreteViewShadowNode;
        
  static ShadowNodeTraits BaseTraits() {
    auto traits = ConcreteViewShadowNode::BaseTraits();
    traits.set(ShadowNodeTraits::Trait::TextKind);
    traits.set(ShadowNodeTraits::Trait::LeafYogaNode);
    traits.set(ShadowNodeTraits::Trait::MeasurableYogaNode);
    return traits;
  }
        
#pragma mark - LayoutableShadowNode

  Size measureContent(
      LayoutContext const &layoutContext,
      LayoutConstraints const &layoutConstraints) const override;
};

} // namespace react
} // namespace facebook
