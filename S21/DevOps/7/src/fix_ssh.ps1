param(
    [string]$InstanceName = "default"  # Параметр по умолчанию
)

Write-Host "Trying to retrieve Vagrant SSH details for instance '$InstanceName'..."

# Получаем SSH-конфиг только для указанного инстанса
$SshConfig = vagrant ssh-config $InstanceName
if ($LASTEXITCODE -ne 0) {
    Write-Host "Error: Could not get SSH config for instance '$InstanceName'"
    Exit 1
}

# Извлекаем путь к ключу
$VagrantSshKey = ($SshConfig | Select-String -Pattern "^  IdentityFile ").ToString().Split(" ",[System.StringSplitOptions]::RemoveEmptyEntries)[1]

if (!$VagrantSshKey -or !$VagrantSshKey.EndsWith("private_key")) {
    Write-Host "Could not determine Vagrant private SSH Key location for instance '$InstanceName'. Unable to proceed."
    Exit 1
}

Write-Host "Key location is: $VagrantSshKey"
Write-Host "Fixing key permissions..."

# Удаляем наследование прав
icacls $VagrantSshKey /c /t /Inheritance:d

# Устанавливаем владельца
icacls $VagrantSshKey /c /t /Grant:r "${env:UserName}":F

# Удаляем лишние права
icacls $VagrantSshKey /c /t /Remove:g Administrator "Authenticated Users" BUILTIN\Administrators BUILTIN Everyone System Users

# Проверяем результат
icacls $VagrantSshKey

Write-Host "Successfully fixed SSH private key permissions for instance '$InstanceName'"