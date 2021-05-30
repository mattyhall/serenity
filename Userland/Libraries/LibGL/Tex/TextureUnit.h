/*
 * Copyright (c) 2021, Jesse Buhagiar <jooster669@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/OwnPtr.h>
#include <LibGL/Tex/Texture2D.h>

namespace GL {

class TextureUnit {
public:
    TextureUnit() = default;

    void bind_texture_to_target(GLenum texture_target, const RefPtr<Texture>& texture);
    void unbind_texture(GLenum texture_target);
    const RefPtr<Texture>& get_bound_texture() const { return m_currently_bound_texture; }

    GLenum currently_bound_target() const { return m_currently_bound_target; }
    bool is_bound() const { return m_currently_bound_texture != nullptr; }

private:
    RefPtr<Texture2D> m_texture_target_2d { nullptr };
    RefPtr<Texture> m_currently_bound_texture { nullptr };
    GLenum m_currently_bound_target;
};

}
