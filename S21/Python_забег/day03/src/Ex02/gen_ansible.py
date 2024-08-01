import argparse
import glob
import yaml

def get_filename_recursive(directory, filename):
    files = glob.glob('{0}/**/{1}'.format(directory, filename), recursive=True)
    return files[0] if len(files) > 0 else None

def generate_ansible(src_root_directory, dest_directory):
    with open('../../materials/todo.yml') as stream:

        todo = yaml.safe_load(stream)
        deploy = [{
            'name': 'Deploy evilcorp exploit',
            'hosts': 'myhosts',
            'tasks': [{
                'name': 'update aptitude repositories',
                'ansible.builtin.shell': 'apt-get update'
            }]
        }]

        for package_name in todo['server']['install_packages']:
            ansible_install_package_task = {
                'name': 'install package {0}'.format(package_name),
                'ansible.builtin.shell': 'yes | apt-get install {0}'.format(package_name)
            }
            deploy[0]['tasks'].append(ansible_install_package_task)

        for file_name in todo['server']['exploit_files']:
            file_full_path = get_filename_recursive(src_root_directory, file_name)
            if (file_full_path == None):
                raise FileNotFoundError('No file "{0}" found in directory {1}'.format(file_name, src_root_directory))
            ansible_copy_file_task = {
                'name': 'copy file {0}'.format(file_name.split('/')[-1]),
                'ansible.builtin.copy': {
                    'src': file_full_path,
                    'dest': '{0}/{1}'.format(dest_directory, file_name.split('/')[-1])
                }
            }
            deploy[0]['tasks'].append(ansible_copy_file_task)

        for shell_command in todo['server']['start_service_commands']:
            ansible_shell_command_task = {
                'name': 'run command {0}'.format(shell_command),
                'ansible.builtin.shell': shell_command
            }
            deploy[0]['tasks'].append(ansible_shell_command_task)

        ansible_run_python_app_task = {
            'name': 'run python pub/sub transactions consumer',
            'ansible.builtin.shell': 'nohup python3 {0}/consumer.py -e {1} &'.format(dest_directory, ','.join(todo['bad_guys']))
        }
        deploy[0]['tasks'].append(ansible_run_python_app_task)

        with open('deploy.yml', 'w', encoding='utf8') as output:
            yaml.dump(deploy, output, default_flow_style=False)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument("-s", "--source", help="source directory", default='.', type=str)
    parser.add_argument("-d", "--destination", help="destination directory", default='~', type=str)
    args = parser.parse_args()
    try:
        generate_ansible(args.source, args.destination)
    except Exception as inst:
        print(inst)
