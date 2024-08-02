from itertools import cycle
from itertools import chain


def fix_wiring(plugs, sockets, cables):
    return map(
        lambda x: f'{x[2][0]} {x[0]} {x[2][1]} {x[1]} {x[2][2]} {x[2][3]}',
        zip(
            filter(lambda x: 'socket' in str(x), sockets),
            filter(lambda x: 'cable' in str(x), cables),
            chain((zip(cycle(['plug', 'plug']),
                       filter(lambda x: 'plug' in str(x), plugs),
                       cycle(['into', 'into']), cycle(['using', 'using']))),
                  zip(cycle(['weld', 'weld']), cycle(['to', 'to']),
                      cycle(['without', 'without']), cycle(['plug',
                                                            'plug'])))))


if __name__ == "__main__":
    plugs = ['plugZ', None, 'plugY', 'plugX']
    sockets = [1, 'socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable2', 'cable1', False]
    print(plugs, '\n', sockets, '\n', cables, '\n',
          list(fix_wiring(plugs=plugs, sockets=sockets, cables=cables)), '\n')

    plugs = ['plug1', 'plug2', 'plug3']
    sockets = ['socket1', 'socket2', 'socket3', 'socket4']
    cables = ['cable1', 'cable2', 'cable3', 'cable4']
    print(plugs, '\n', sockets, '\n', cables, '\n',
          list(fix_wiring(plugs=plugs, sockets=sockets, cables=cables)), '\n')

    plugs = []
    sockets = [None, 'socket2', 'socket3', 'socket4']
    cables = ['cable1', 3, 'cable3', 6.0]
    print(plugs, '\n', sockets, '\n', cables, '\n',
          list(fix_wiring(plugs=plugs, sockets=sockets, cables=cables)), '\n')

    plugs = ['plug-1']
    sockets = ['socket1', 'socket3', 'socket4']
    cables = []
    print(plugs, '\n', sockets, '\n', cables, '\n',
          list(fix_wiring(plugs=plugs, sockets=sockets, cables=cables)), '\n')

    plugs = ['plug-1', 'plug-2', 'plug-3']
    sockets = []
    cables = ['cable1', 3, 'cable3']
    print(plugs, '\n', sockets, '\n', cables, '\n',
          list(fix_wiring(plugs=plugs, sockets=sockets, cables=cables)), '\n')

    plugs = []
    sockets = []
    cables = []
    print(plugs, '\n', sockets, '\n', cables, '\n',
          list(fix_wiring(plugs=plugs, sockets=sockets, cables=cables)), '\n')
