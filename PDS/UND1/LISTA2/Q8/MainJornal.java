import java.util.ArrayList;
import java.util.List;

public class MainJornal {
    public static void main(String[] args) {
        System.out.println("--- Sistema de Gerenciamento de Jornal Digital ---");

        // 1. Criando Pessoas (Autores e Revisores)
        System.out.println("\nCriando Autores e Revisores...");
        Autor autor1 = new Autor("João Escrivão", "joao.e@jornal.com", "Tecnologia");
        Autor autor2 = new Autor("Maria Reportagem", "maria.r@jornal.com", "Política");
        Revisor revisor1 = new Revisor("Pedro Lira", "pedro.l@jornal.com", "Geral");
        Revisor revisor2 = new Revisor("Ana Corretora", "ana.c@jornal.com", "Economia");

        // Polimorfismo: Tratando Autores e Revisores como Pessoas
        System.out.println("\n--- Informações de Pessoas no Sistema (Polimorfismo) ---");
        List<Pessoa> equipe = new ArrayList<>();
        equipe.add(autor1);
        equipe.add(autor2);
        equipe.add(revisor1);
        equipe.add(revisor2);

        for (Pessoa p : equipe) {
            p.exibirInformacoes(); // Cada um executa sua versão sobrescrita
        }

        // 2. Criando Artigos
        System.out.println("\n--- Criação e Processamento de Artigos ---");
        Artigo artigo1 = new Artigo(
            "Novas Tendências em Inteligência Artificial",
            "A inteligência artificial continua a evoluir rapidamente, com novas aplicações surgindo...",
            autor1
        );

        Artigo artigo2 = new Artigo(
            "Impacto da Reforma Tributária na Economia",
            "A proposta de reforma tributária gera debates acalorados entre economistas e políticos...",
            autor2
        );

        artigo1.exibirDetalhes();
        artigo2.exibirDetalhes();

        // 3. Processo de Revisão e Publicação
        System.out.println("\n--- Fluxo de Revisão e Publicação ---");

        // Artigo 1: Enviando para revisão
        artigo1.enviarParaRevisao();
        revisor1.revisarArtigo(artigo1); // Revisor revisa
        artigo1.publicar(); // Tenta publicar (deve falhar pois ainda não está "Revisado")
        System.out.println("Status final do Artigo 1 após tentativa de publicação: " + artigo1.getStatus());

        // Se o revisor mudar o status para "Revisado" no método revisarArtigo()
        System.out.println("\n--- Artigo 1: Nova tentativa de Publicação ---");
        artigo1.setStatus("Revisado"); // Simulando que a revisão foi concluída com sucesso
        artigo1.publicar();
        artigo1.exibirDetalhes();

        // Artigo 2: Enviando para revisão
        artigo2.enviarParaRevisao();
        revisor2.revisarArtigo(artigo2);
        artigo2.publicar();
        artigo2.exibirDetalhes();

        // 4. Verificando artigos publicados por autor (Encapsulamento e Relacionamento)
        System.out.println("\n--- Artigos de João Escrivão ---");
        for (Artigo a : autor1.getArtigosPublicados()) {
            System.out.println("- " + a.getTitulo() + " (Status: " + a.getStatus() + ")");
        }

        System.out.println("\n--- Artigos de Maria Reportagem ---");
        for (Artigo a : autor2.getArtigosPublicados()) {
            System.out.println("- " + a.getTitulo() + " (Status: " + a.getStatus() + ")");
        }

        // Exemplo de Encapsulamento: tentativa de acesso direto a atributo privado
        // autor1.nome = "Novo Nome"; // Isso geraria um erro de compilação!
        autor1.setNome("João Escrivão (Atualizado)"); // Acesso via setter
        System.out.println("\nNome do autor 1 atualizado (via setter): " + autor1.getNome());
    }
}