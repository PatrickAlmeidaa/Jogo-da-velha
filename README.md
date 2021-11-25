# Jogo-da-velha
Jogo da velha com "inteligência artificial" simples

# Enunciado
O jogo da velha é um dos jogos mais antigos da humanidade; os primeiros registros dele são do século I antes de
Cristo, no Império Romano. Implemente uma versão simplicada do jogo da velha utilizando uma matriz 3x3 para que
o usuário possa jogar contra o computador. A sua meta é fazer do computador o mais esperto possível: a cada jogada
do usuário, avalie estrategicamente como o computador irá jogar.

# Entrada e Saída
Inicialmente, a entrada é composta pela identificação da célula onde o usuário fará sua primeira jogada: l c,
sendo l a idenficação da linha e c da coluna, tal que 0 ≤ l, c ≤ 2. Para cada jogada do usuário, será exibida a
jogada do computador, também no formato l c. Tão logo termine uma partida, deverá ser exibido o placar: seguido
do ganhador: 0 para empate, 1 caso o usuário tenha vencido ou −1 caso o usuário tenha perdido. Ao final das
3 jogadas inciais, a saída será composta pelo placar numero_partidas_usuario numero_partidas_computador. O
usuário poderá escolher entre parar o jogo (p) ou continuar (c). Caso o usuário escolha continuar, serão executadas
mais duas rodadas, ao final das quais será exibido o placar atualizado e assim sucessivamente. Se a escolha for parar,
será exibido quem é o vencedor: usuário ou computador
