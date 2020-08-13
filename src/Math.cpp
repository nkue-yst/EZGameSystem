/**
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#include <EZGS/Math.hpp>

using std::cos;
using std::sin;

namespace ezgs
{
    const Vec2 Vec2::ZERO(0.0f, 0.0f);

    static float mat4_identity[4][4] = {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f }
    };
    const Mat4 Mat4::Identity(mat4_identity);

    Mat4 Mat4::CreateScale(float x_scale, float y_scale, float z_scale)
    {
        float res[4][4] =
        {
            { x_scale,    0.0f,    0.0f, 0.0f },
            {    0.0f, y_scale,    0.0f, 0.0f },
            {    0.0f,    0.0f, z_scale, 0.0f },
            {    0.0f,    0.0f,    0.0f, 1.0f }
        };
        return Mat4(res);
    }

    Mat4 Mat4::RotationZ(float theta)
    {
        float res[4][4] =
        {
            {  cos(theta), sin(theta), 0.0f, 0.0f },
            { -sin(theta), cos(theta), 0.0f, 0.0f },
            {        0.0f,       0.0f, 1.0f, 0.0f },
            {        0.0f,       0.0f, 0.0f, 1.0f }
        };
        return Mat4(res);
    }

    Mat4 Mat4::Translation(const Vec3& trans)
    {
        float res[4][4] =
        {
            { 1.0f, 0.0f, 0.0f, 0.0f },
            { 0.0f, 1.0f, 0.0f, 0.0f },
            { 0.0f, 0.0f, 1.0f, 0.0f },
            { trans.x, trans.y, trans.z, 1.0f }
        };
        return Mat4(res);
    }

    Mat4 Mat4::CreateSimpleView(float width, float height)
    {
        float res[4][4] =
        {
            { 2.0f / width,        0.0f, 0.0f, 0.0f },
            {       0.0f, 2.0f / height, 0.0f, 0.0f },
            {       0.0f,        0.0f, 1.0f, 0.0f },
            {       0.0f,        0.0f, 1.0f, 1.0f }
        };
        return Mat4(res);
    }
}
