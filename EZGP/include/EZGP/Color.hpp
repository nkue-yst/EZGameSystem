/**
 * @file Color.hpp
 * @brief 色関連
 * @author Yoshito Nakaue
 * @date 2020/09/10
 */

#pragma once
#include <cstdint>

namespace ezgp
{
    struct Color
    {
    public:
        Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 255);

        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;

        friend Color operator+(Color a, Color b)
        {
            return Color(
                a.red + b.red,
                a.green + b.green,
                a.blue + b.blue,
                255
            );
        }

        friend Color operator-(Color a, Color b)
        {
            return Color(
                a.red - b.red,
                a.green - b.green,
                a.blue - b.blue,
                255
            );
        }

        static const Color AZURE;    // azure
        static const Color BLACK;    // 黒
        static const Color BLUE;     // 青
        static const Color BROWN;    // 茶
        static const Color CREAM;    // クリーム色
        static const Color CYAN;     // シアン
        static const Color GRAY;     // 灰色
        static const Color GREEN;    // 緑
        static const Color IVORY;    // アイボリー
        static const Color KHAKI;    // カーキ
        static const Color LEMON;    // レモンイエロー
        static const Color LIME;     // ライムグリーン
        static const Color MAGENTA;  // マゼンタ
        static const Color NAVY;     // ネイビー
        static const Color ORANGE;   // オレンジ
        static const Color PINK;     // ピンク
        static const Color PURPLE;   // 紫
        static const Color RED;      // 赤
        static const Color SKY;      // スカイブルー
        static const Color SNOW;     // スノウホワイト
        static const Color VIOLET;   // バイオレット
        static const Color WHITE;    // 白
        static const Color YELLOW;   // 黄
    };
}
