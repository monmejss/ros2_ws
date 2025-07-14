# Corteza occipital se divide en dos.
# Corriente ventral(¿que?) - Corriente dorsal(¿donde?)

import rclpy
from rclpy.node import Node
from gazebo_msgs.msg import ModelStates # Para pose
from mod_interfaces.msg import DimensionesObj, CoordenadasObj

# Dimensiones objeto 1 - objeto 2
lata_radio = 0.033
lata_altura = 0.115
esfera_radio = 0.04
esfera_altura = 0.0

# Subnodo: Corriente ventral
class corrienteVentral(Node):
    def __init__(self):
        super().__init__('corriente_ventral')
        # Crea publicador en el topico vision/corriente_ventral
        self.pub = self.create_publisher(DimensionesObj, 'vision/corriente_ventral', 10)
        
        #timer que llama a publica_dimensiones
        self.timer = self.create_timer(1.0, self.publica_dimensiones)
        
    def publica_dimensiones(self):
        lata = DimensionesObj()
        lata.model_name = 'coke_can'
        lata.radius = lata_radio
        lata.height = lata_altura
        self.get_logger().info(f'Publicando lata: {lata}')
        self.pub.publish(lata)
        
        esfera = DimensionesObj()
        esfera.model_name = 'ball'
        esfera.radius = esfera_radio
        esfera.height = esfera_altura
        self.get_logger().info(f'Publicando esfera: {esfera}')
        self.pub.publish(esfera)
        
        self.get_logger().info('Dimensiones publicadas')
        self.destroy_timer(self.timer)
        
# Subnodo: Corriente dorsal
class corrienteDorsal(Node):
    def __init__(self):
        super().__init__('corriente_dorsal')
        self.pub = self.create_publisher(CoordenadasObj, 'vision/corriente_dorsal', 10)
        # Se suscribe al pose
        self.create_subscription(ModelStates, '/demo/model_states_demo', self.publica_coordenadas, 10)

    def publica_coordenadas(self, msg: ModelStates):
        for name, pose in zip(msg.name, msg.pose):
            if name in('coke_can', 'ball'):
                objeto = CoordenadasObj()
                objeto.model_name = name
                objeto.pose = pose
                self.get_logger().info(f'Publicando pose: {name}')
                self.pub.publish(objeto)
                self.get_logger().info(f'Publicado')
            
            
def main(args=None):
    rclpy.init(args=args)
    ventral = corrienteVentral()
    dorsal = corrienteDorsal()
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(ventral)
    executor.add_node(dorsal)
    
    try:
        executor.spin()
    finally:
        ventral.destroy_node()
        dorsal.destroy_node()
        
if __name__ == '__main__':
    main()