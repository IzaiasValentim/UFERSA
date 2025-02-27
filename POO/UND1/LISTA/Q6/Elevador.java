
class Elevador {
    private int capacidadeDePessoas;
    private int lotacaoAtual;
    private int totalDeAndares;
    private int andarAtual;

    Elevador(int capacidade, int totalAndares) {
        capacidadeDePessoas = capacidade;
        lotacaoAtual = 0;
        totalDeAndares = totalAndares;
        andarAtual = 0; // Terreo;
    }

    void statusElevador() {
        System.out.println(
                "####\n O elevador está no " + andarAtual + "º andar de " + totalDeAndares + "º andares." +
                        "\n Contém " + lotacaoAtual + " de " + capacidadeDePessoas + " pessoas.\n####");
    }

    void entra() {
        System.out.println("*-------------");
        if (lotacaoAtual < capacidadeDePessoas) {
            lotacaoAtual++;
            System.out.println("Uma pessoa entrou, situação atual:");
            this.statusElevador();
        } else {
            System.out.println("O elevador está lotado!");
            this.statusElevador();
        }
        System.out.println("------------*\n");
    }

    void sai() {
        System.out.println("*-------------");
        if (lotacaoAtual > 0) {
            lotacaoAtual--;
            System.out.println("Uma pessoa saiu, situação atual:");
            this.statusElevador();
        } else {
            System.out.println("O elevador não contem ninguém para sair.");
            this.statusElevador();
        }
        System.out.println("------------*\n");
    }

    void sobe() {
        System.out.println("*-------------");
        if (andarAtual < totalDeAndares) {
            andarAtual++;
            System.out.println("^- O elevador subiu um andar, situação atual:");
            this.statusElevador();
        } else {
            System.out.println("^- O elevador não consegue subir um andar, situação atual:");
            this.statusElevador();
        }
        System.out.println("------------*\n");
    }

    void desce() {
        System.out.println("*-------------");
        if (andarAtual > 0) {
            andarAtual--;
            System.out.println("v- O elevador desceu um andar, situação atual:");
            this.statusElevador();
        } else {
            System.out.println("^- O elevador não consegue descer um andar, situação atual:");
            this.statusElevador();
        }
        System.out.println("------------\n*");
    }
}