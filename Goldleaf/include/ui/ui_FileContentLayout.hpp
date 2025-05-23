
/*

    Goldleaf - Multipurpose homebrew tool for Nintendo Switch
    Copyright © 2018-2025 XorTroll

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#pragma once
#include <ui/ui_Includes.hpp>

namespace ui {

    class FileContentLayout : public pu::ui::Layout {
        private:
            u32 line_offset;
            u32 x_offset;
            u32 available_line_count;
            u32 max_line_length;
            std::vector<std::string> read_lines;
            size_t cur_read_lines_max_length;
            bool read_hex;
            std::string path;
            pu::ui::elm::TextBlock::Ref cnt_text;
            fs::Explorer *file_exp;

            inline std::vector<std::string> ReadLines(const u32 line_offset, const u32 count) {
                if(this->read_hex) {
                    return this->file_exp->ReadFileFormatHex(this->path, line_offset, count);
                }
                else {
                    return this->file_exp->ReadFileLines(this->path, line_offset, count);
                }
            }

            void OnInput(const u64 keys_down, const u64 keys_up, const u64 keys_held, const pu::ui::TouchPoint touch_pos);
            bool ScrollUp();
            bool ScrollDown();
            bool MoveLeft();
            bool MoveRight();
            void UpdateLineLimits();
            void UpdateLines();

        public:
            FileContentLayout();
            PU_SMART_CTOR(FileContentLayout)

            void LoadFile(const std::string &path, const std::string &pres_path, fs::Explorer *exp, const bool read_hex);
    };

}
