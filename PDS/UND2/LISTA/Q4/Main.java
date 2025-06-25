package Q4;

// Classe Cliente para demonstrar a cadeia de decora��o
class ClienteDecorator {
    public static void main(String[] args) {
        // Pedido simples
        Pedido pedidoBase = new PedidoSimples();
        System.out.println("Descri��o: " + pedidoBase.getDescricao());
        System.out.println("Custo Total: R$" + pedidoBase.calcularCusto()); // Sa�da: R$50.0

        System.out.println("--------------------");

        // Pedido com embalagem para presente
        Pedido pedidoComPresente = new EmbalagemParaPresenteDecorador(new PedidoSimples());
        System.out.println("Descri��o: " + pedidoComPresente.getDescricao());
        System.out.println("Custo Total: R$" + pedidoComPresente.calcularCusto()); // Sa�da: R$60.0

        System.out.println("--------------------");

        // Pedido com frete expresso e seguro
        Pedido pedidoComFreteESeguro = new FreteExpressoDecorador(new SeguroDecorador(new PedidoSimples()));
        System.out.println("Descri��o: " + pedidoComFreteESeguro.getDescricao());
        System.out.println("Custo Total: R$" + pedidoComFreteESeguro.calcularCusto()); // Sa�da: R$90.0 (50 + 15 + 25)

        System.out.println("--------------------");

        // Pedido com todas as funcionalidades (cadeia de decora��o completa)
        Pedido pedidoCompleto = new EmbalagemParaPresenteDecorador(
                new FreteExpressoDecorador(
                        new SeguroDecorador(
                                new PedidoSimples()
                        )));
        System.out.println("Descri��o: " + pedidoCompleto.getDescricao());
        System.out.println("Custo Total: R$" + pedidoCompleto.calcularCusto()); // Sa�da: R$100.0 (50 + 15 + 25 + 10)
    }
}
