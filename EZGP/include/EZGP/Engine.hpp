/**
 * @author Yoshito Nakaue
 * @date 2020/09/08
 */

#pragma once
#include <chrono>
#include <thread>
#include <iostream>

namespace ezgp
{
    // �V�X�e����������
    void EZGP_Init();

    // �V�X�e���̍X�V
    bool Update();

    void EndLoop();

    /**
     * @brief �w�莞�ԃV�X�e�����~����
     * @param duration ��~����(�b)
     * @return �Ȃ�
     */
    template<typename T>
    void Delay(T duration)
    {
        duration *= 1000000;
        std::this_thread::sleep_for(
            std::chrono::microseconds(static_cast<int>(duration))
        );
    }

    // �V�X�e�����I��
    void EZGP_Quit();
}
