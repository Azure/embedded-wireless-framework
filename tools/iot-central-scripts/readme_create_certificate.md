## Steps to create self-signed certs using openssl:
Open command prompt in administrator mode.

#Set x509 configuration file for common name in cert.

cat > x509_config.cfg <<EOT
[req]
req_extensions = client_auth
distinguished_name = req_distinguished_name

[req_distinguished_name]

[ client_auth ]
basicConstraints = CA:FALSE
keyUsage = digitalSignature, keyEncipherment
extendedKeyUsage = clientAuth
EOT

# Generate private key and certificate
Create RSA self-signed certs:

openssl genrsa -out device_ec_key.pem 2048
openssl req -new -days 30 -nodes -x509 -key device_ec_key.pem -out device_ec_cert.pem -config x509_config.cfg -subj "//CN=<Same as device Id>"

OR

Create RSA self-signed cert:
openssl req -new -x509 -nodes -days 365 -newkey ec -pkeyopt ec_paramgen_curve:secp384r1 -keyout device_ec_key.pem -out device_ec_cert.pem -config x509_config.cfg -subj "/CN=<Same as device Id>"

# Generate source files
Run the generate-source-files.bat file with option for modem. (1 : Quectel , 2: Renesas)

> WARNING: Certificates created by these commands MUST NOT be used in production-level code.