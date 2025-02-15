/*
 * Copyright (c) 2018-2021, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <LibWeb/Layout/Box.h>
#include <LibWeb/Layout/LineBox.h>

namespace Web::Layout {

// https://www.w3.org/TR/css-display/#block-container
class BlockContainer : public Box {
    GC_CELL(BlockContainer, Box);

public:
    BlockContainer(DOM::Document&, DOM::Node*, GC::Ref<CSS::ComputedProperties>);
    BlockContainer(DOM::Document&, DOM::Node*, NonnullOwnPtr<CSS::ComputedValues>);
    virtual ~BlockContainer() override;

    Painting::PaintableWithLines const* paintable_with_lines() const;

    virtual GC::Ptr<Painting::Paintable> create_paintable() const override;

private:
    virtual bool is_block_container() const final { return true; }
};

template<>
inline bool Node::fast_is<BlockContainer>() const { return is_block_container(); }

}
