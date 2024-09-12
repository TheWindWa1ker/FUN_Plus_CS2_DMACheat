// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.hpp"

extern Map G_map;

void web_radar()
{

    try
    {
        while (1)
        {
            if (G_map.EnableWebRadar) {

                LOG("网页雷达启动 \n");

                // @easywsclient
                WSADATA wsa_data{};
                const auto wsa_startup = WSAStartup(MAKEWORD(2, 2), &wsa_data);
                if (wsa_startup != 0)
                {
                    LOG_ERROR("初始化Winsock失败");
                    this_thread::sleep_for(chrono::seconds(5));
                    continue;
                }

                const auto ipv4_address = utils::get_ipv4_address();
                if (ipv4_address.empty())
                {
                    LOG_ERROR("获取ipv4地址失败，请手动设置");
                    this_thread::sleep_for(chrono::seconds(5));
                    continue;
                }

                const auto formatted_address = format("ws://{}:22006/cs2_webradar", utils::get_ipv4_address());
                auto web_socket = easywsclient::WebSocket::from_url(formatted_address);//easywsclient::WebSocket::from_url("ws://192.168.2.243:22006/cs2_webradar");
                if (!web_socket)
                {
                    LOG_ERROR("连接失败 web socket: ('%s')", formatted_address.data());
                    this_thread::sleep_for(chrono::seconds(5));
                    continue;
                }

                LOG("连接成功 web socket ('%s')", formatted_address.data());

                auto start = chrono::system_clock::now();

                for (;;)
                {
                    const auto now = chrono::system_clock::now();
                    const auto duration = now - start;
                    if (duration >= chrono::milliseconds(10))
                    {
                        start = now;

                        m_features.run();
                        try
                        {
                            // LOG("%s", m_features.get_data().dump().data());
                            web_socket->send(m_features.get_data().dump());
                        }
                        catch (...)
                        {
                            cout << "erro" << endl;
                        }

                    }

                    web_socket->poll();
                    if (web_socket->getReadyState() == 1)
                    {
                        break;
                    }

                    this_thread::sleep_for(chrono::milliseconds(1));
                }

                //system("pause");
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "运行网页雷达发生错误: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "未知错误" << std::endl;
    }

    return;
}