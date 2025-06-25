package Q3;

class AplicacaoUI {
    private FabricaDeComponentesUI fabricaAtual;
    private Botao botao;
    private CaixaDeTexto caixaDeTexto;
    private Menu menu;

    public AplicacaoUI(FabricaDeComponentesUI fabricaInicial) {
        this.fabricaAtual = fabricaInicial;
        criarComponentes();
    }

    private void criarComponentes() {
        this.botao = fabricaAtual.criarBotao();
        this.caixaDeTexto = fabricaAtual.criarCaixaDeTexto();
        this.menu = fabricaAtual.criarMenu();
    }

    public void exibirUI() {
        System.out.println("\n--- Exibindo UI com o tema atual ---");
        botao.renderizar();
        caixaDeTexto.exibir();
        menu.abrir();
    }

    // Método para alternar o tema dinamicamente
    public void alternarTema(FabricaDeComponentesUI novaFabrica) {
        this.fabricaAtual = novaFabrica;
        criarComponentes(); // Recria os componentes com a nova fábrica
        System.out.println("\nTema alterado com sucesso!");
    }

    public static void main(String[] args) {
        // Iniciar com tema claro
        AplicacaoUI app = new AplicacaoUI(new FabricaTemaClaro());
        app.exibirUI();

        // Alternar para tema escuro
        app.alternarTema(new FabricaTemaEscuro());
        app.exibirUI();

        // Alternar para tema de alto contraste
        app.alternarTema(new FabricaTemaAltoContraste());
        app.exibirUI();
    }
}
