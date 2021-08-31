#include<iostream>
#include<SFML/Graphics.hpp>
/// Incluindo a biblioteca gr�fica do SFML

using namespace std;
using namespace sf;

int main()
{
    /// RenderWindow -> classe de janela para renderiza��o 2D do SFML

    int base=640, altura=480;
    string titulo = "Criando Janela com SFML";

    /// Argumentos do contrutor da janela:
    /// - modo de v�deo (VideoMode)
    /// - t�tulo
    /// - estilo da janela (opcional)
    /// - Configura��es da janela (ContextSettings, opcional)

    ContextSettings settings;
    settings.depthBits = 24;
    settings.antialiasingLevel = 8;
    settings.stencilBits = 8;

    Uint32 estilo = Style::Default;
    /// Padr�o: barra de t�tulo, redimension�vel, com "X"
    RenderWindow window(VideoMode(base, altura), titulo, estilo, settings);

    /// A janela pode ter outros estilos

    /// A janela apareceu e desapareceu logo.
    /// Para que isso n�o aconte�a, devemos criar
    /// um loop para a janela.

    while(window.isOpen())
    {
        Event e;
        /// Procurando eventos
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
            {
               int resp;
               cout << "Tem certeza que quer fechar? (1-Sim, 0-Nao)\n";
               cin >> resp;
               if(resp==1)
                    window.close();
            }
            /// Podemos bloquear o fechamento da janela.
            /// Se o usu�rio clicar no "X" da janela, ela facha.
        }
        window.clear(); /// Limpa o buffer de cores da janela (na Cor preta)
        window.display(); /// Exibe o buffer de cores da janela na tela
    }
}
