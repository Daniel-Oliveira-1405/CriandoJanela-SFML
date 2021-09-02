#include<iostream>
#include<SFML/Graphics.hpp>
/// Incluindo a biblioteca gráfica do SFML

using namespace std;
using namespace sf;
/// Usando a namespace do SFML

int main()
{

    RenderWindow window(VideoMode(640, 480), "Eventos");

    /// Loop da janela
    while(window.isOpen())
    {
        Event evento;
        /// Procurando evento
        while(window.pollEvent(evento))
        {
            switch(evento.type)
            {
            /// Se o usuário clicar no 'X' da janela, ela fecha
            case Event::Closed:
                window.close();
                break;

            /// Se um texto for entrado
            case Event::TextEntered:
                cout << "Texto entrado: " << (char)evento.text.unicode << endl;
                break;

            /// Se uma tecla for pressionada (tecla para baixo)
            case Event::KeyPressed:
                if(evento.key.code == Keyboard::Return)
                    cout << "Tecla ENTER pressionada!\n";
                if(evento.key.alt) cout << "Com ALT\n";
                if(evento.key.control) cout << "Com CTRL\n";
                if(evento.key.shift) cout << "Com SHIFT\n";
                if(evento.key.system) cout << "Com tecla do sistema\n";
                break;

            /// Se uma tecla for liberada
            case Event::KeyReleased:
                if(evento.key.code == Keyboard::Return)
                    cout << "Tecla ENTER liberada!\n";
                break;

            /// Se o mouse se mover dentro da janela
            case Event::MouseMoved:
                cout << "Nova posicao do mouse (X): " << evento.mouseMove.x << "\n";
                cout << "Nova posicao do mouse (Y): " << evento.mouseMove.y << "\n";
                /// Posição do mouse EM RELAÇÃO À JANELA
                break;

            /// Se o mouse sair da janela
            case Event::MouseLeft:
                cout << "O cursor do mouse saiu da janela.\n";
                break;

            /// Se o mouse entrar na janela
            case Event::MouseEntered:
                cout << "O cursor do mouse entrou na janela.\n";
                break;

            /// Caso algum botão do mouse for pressionado (botão para baixo)
            case Event::MouseButtonPressed:
                if(evento.mouseButton.button == Mouse::Left)
                    cout << "Botao ESQUERDO do mouse pressionado.\n";
                else if(evento.mouseButton.button == Mouse::Right)
                    cout << "Botao DIREITO do mouse pressionado.\n";
                else if(evento.mouseButton.button == Mouse::Middle)
                    cout << "Botao DO MEIO do mouse pressionado.\n";

                cout << "Posicao do clique X: " << evento.mouseButton.x << endl;
                cout << "Posicao do clique Y: " << evento.mouseButton.y << endl;
                break;

            /// Caso algum botão do mouse for liberado (botão para baixo)
            case Event::MouseButtonReleased:
                if(evento.mouseButton.button == Mouse::Left)
                    cout << "Botao ESQUERDO do mouse liberado.\n";
                else if(evento.mouseButton.button == Mouse::Right)
                    cout << "Botao DIREITO do mouse liberado.\n";
                else if(evento.mouseButton.button == Mouse::Middle)
                    cout << "Botao DO MEIO do mouse liberado.\n";

                cout << "Posicao do clique X: " << evento.mouseButton.x << endl;
                cout << "Posicao do clique Y: " << evento.mouseButton.y << endl;
                break;

            /// Se for rodada a roda do mouse
            case Event::MouseWheelScrolled:
                cout << "Rotacao da roda: " << evento.mouseWheel.delta << endl;
                cout << "Posicao do cursor do mouse (X): " << evento.mouseWheel.x << endl;
                cout << "Posicao do cursor do mouse (Y): " << evento.mouseWheel.y << endl;
                break;

            /// Caso algum sensor tenha mudado (se seu computador tiver)
            case Event::SensorChanged:
                if(evento.sensor.type == Sensor::Accelerometer)
                    cout << "Sensor do acelerômetro mudado!\n";
                else if(evento.sensor.type == Sensor::Gyroscope)
                    cout << "Sensor do giroscópio mudado!\n";
                else if(evento.sensor.type == Sensor::Gravity)
                    cout << "Sensor de gravidade mudado!\n";
                else if(evento.sensor.type == Sensor::Magnetometer)
                    cout << "Sensor de campo magnetico mudado!\n";
                else if(evento.sensor.type == Sensor::Orientation)
                    cout << "Sensor de orientacao mudado!\n";
                else if(evento.sensor.type == Sensor::UserAcceleration)
                    cout << "Sensor de aceleracao do usuario mudado!\n";

                cout << "X: " << evento.sensor.x << endl;
                cout << "Y: " << evento.sensor.y << endl;
                cout << "Z: " << evento.sensor.z << endl;
                break;

            /// Caso o usuário comece a tocar na tela
            case Event::TouchBegan:
                cout << "Usuário tocou na tela!" << endl;
                cout << "Posicao X: " << evento.touch.x << endl;
                cout << "Posicao Y: " << evento.touch.y << endl;
                /// Em caso de mais de um dedo
                cout << "Dedo: " << evento.touch.finger << endl;
                break;

            /// Caso o usuário tire o dedo na tela
            case Event::TouchEnded:
                cout << "Usuário tirou o dedo da tela!" << endl;
                cout << "Posicao X: " << evento.touch.x << endl;
                cout << "Posicao Y: " << evento.touch.y << endl;
                /// Em caso de mais de um dedo
                cout << "Dedo: " << evento.touch.finger << endl;
                break;

            /// Caso o usuário arraste o dedo
            case Event::TouchMoved:
                cout << "O usuário moveu o dedo na tela!\n";
                cout << "Posicao X: " << evento.touch.x << endl;
                cout << "Posicao Y: " << evento.touch.y << endl;
                /// Em caso de mais de um dedo
                cout << "Dedo: " << evento.touch.finger << endl;
                break;

            /// Se um controle de joystick for conectado
            case Event::JoystickConnected:
                cout << "Controle de joystick conectado.\n";
                cout << "ID: " << evento.joystickConnect.joystickId << endl;
                break;

            /// Se um controle de joystick for desconectado
            case Event::JoystickDisconnected:
                cout << "Controle de joystick desconectado.\n";
                cout << "ID: " << evento.joystickConnect.joystickId << endl;
                break;

            /// Se um joystick mover
            case Event::JoystickMoved:
                if (evento.joystickMove.axis == Joystick::X)
                {
                    cout << "Eixo X movido!" << endl;
                    cout << "ID do joystick: " << evento.joystickMove.joystickId << endl;
                    cout << "Nova posicao: " << evento.joystickMove.position << endl;
                }

                /// Eixos de movimento do joystick
                /// Joystick::X
                /// Joystick::Y
                /// Joystick::Z
                /// Joystick::R
                /// Joystick::U
                /// Joystick::V
                /// Joystick::PovX
                /// Joystick::PovY
                break;

            /// Caso algum botão do joystick for pressionado
            case Event::JoystickButtonPressed:
                cout << "Botao de joystick pressionado!" << endl;
                cout << "ID do joystick: " << evento.joystickButton.joystickId << endl;
                cout << "Botao: " << evento.joystickButton.button << endl;
                break;

            /// Caso algum botão do joystick for liberado
            case Event::JoystickButtonReleased:
                cout << "Botao de joystick liberado!" << endl;
                cout << "ID do joystick: " << evento.joystickButton.joystickId << endl;
                cout << "Botao: " << evento.joystickButton.button << endl;
                break;

            }

        }
        window.clear(Color::Blue); /// Limpa o buffer de cores da janela na cor azul
        window.display(); /// Exibe o buffer de cores na janela
    }
}
