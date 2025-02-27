
class Main {
    public static void main(String args[]) {
        Elevador elevador = new Elevador(4, 3);
        // Entram 2 de 4 pessoas
        elevador.entra();
        elevador.entra();

        // Sobre 3 de 3 andares
        elevador.sobe();
        elevador.sobe();
        elevador.sobe();
        elevador.sobe(); // Não permite subir. Topo.

        // Lota 4 de 4 pessoas
        elevador.entra();
        elevador.entra();
        elevador.entra(); // Não permite a entrada. Lotado.
        elevador.entra(); // Não permite a entrada. Lotado.

        elevador.desce(); // 2 andar.
        elevador.sai(); // 3 pessoas.
        elevador.entra(); // 4 pessoas

        elevador.desce(); // 1 andar.
        elevador.desce(); // Terreo.
        elevador.desce(); // Não permite descer. Terreo.

        // Elevador esvazia:
        elevador.sai();
        elevador.sai();
        elevador.sai();
        elevador.sai();
    }
}