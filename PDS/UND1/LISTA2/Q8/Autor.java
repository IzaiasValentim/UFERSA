import java.util.ArrayList;
import java.util.List;

public class Autor extends Pessoa {
    private String especialidade;
    private List<Artigo> artigosPublicados; // Relacionamento com Artigo

    public Autor(String nome, String email, String especialidade) {
        super(nome, email); // Chama o construtor da superclasse Pessoa
        this.especialidade = especialidade;
        this.artigosPublicados = new ArrayList<>();
    }

    // Métodos Getters
    public String getEspecialidade() {
        return especialidade;
    }

    public List<Artigo> getArtigosPublicados() {
        return artigosPublicados;
    }

    // Métodos Setters
    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }

    // Método para adicionar um artigo publicado
    public void adicionarArtigoPublicado(Artigo artigo) {
        this.artigosPublicados.add(artigo);
    }

    @Override
    public void exibirInformacoes() { // Polimorfismo: sobrescreve o método da superclasse
        super.exibirInformacoes();
        System.out.println("  Função: Autor, Especialidade: " + this.especialidade);
        System.out.println("  Artigos Publicados: " + this.artigosPublicados.size());
    }

    public void escreverArtigo(String titulo, String conteudo) {
        System.out.println(this.getNome() + " está escrevendo um novo artigo: '" + titulo + "'");
        // Em um sistema real, aqui o artigo seria criado e associado a este autor.
    }
}