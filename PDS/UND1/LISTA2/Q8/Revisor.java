public class Revisor extends Pessoa {
    private String areaRevisao;
    private int artigosRevisadosNoMes;

    public Revisor(String nome, String email, String areaRevisao) {
        super(nome, email); // Chama o construtor da superclasse Pessoa
        this.areaRevisao = areaRevisao;
        this.artigosRevisadosNoMes = 0;
    }

    // Métodos Getters
    public String getAreaRevisao() {
        return areaRevisao;
    }

    public int getArtigosRevisadosNoMes() {
        return artigosRevisadosNoMes;
    }

    // Métodos Setters
    public void setAreaRevisao(String areaRevisao) {
        this.areaRevisao = areaRevisao;
    }

    // Método específico
    public void revisarArtigo(Artigo artigo) {
        if (artigo.getStatus().equals("Em Revisão")) {
            System.out.println(this.getNome() + " está revisando o artigo: '" + artigo.getTitulo() + "'");
            this.artigosRevisadosNoMes++;
            // Lógica para aplicar correções e mudar status do artigo
            artigo.setStatus("Revisado");
        } else {
            System.out.println("Artigo '" + artigo.getTitulo() + "' não está pronto para revisão ou já foi revisado.");
        }
    }

    @Override
    public void exibirInformacoes() { // Polimorfismo: sobrescreve o método da superclasse
        super.exibirInformacoes();
        System.out.println("  Função: Revisor, Área: " + this.areaRevisao);
        System.out.println("  Artigos Revisados no Mês: " + this.artigosRevisadosNoMes);
    }
}