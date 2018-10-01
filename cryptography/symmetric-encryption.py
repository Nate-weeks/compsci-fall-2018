import nacl.secret
import nacl.utils

# This must be kept secret, this is the combination to your safe
key = nacl.utils.random(nacl.secret.SecretBox.KEY_SIZE)

# This is your safe, you can use it to encrypt or decrypt messages
box = nacl.secret.SecretBox(key)

# This is our message to send, it must be a bytestring as SecretBox will
#   treat it as just a binary blob of data.
string_message = input("Please type a message you would you like to encrypt:  ")
message = bytes(string_message, 'utf-8')

# Encrypt our message, it will be exactly 40 bytes longer than the
#   original message as it stores authentication information and the
#   nonce alongside it.
print("encrypting message with nonce and mac authentication information")

encrypted = box.encrypt(message)

print("length of unencrypted message = " + str(len(message)))
print("length of encrypted message = " + str(len(encrypted)))
assert len(encrypted) == len(message) + box.NONCE_SIZE + box.MACBYTES

# This is a nonce, it *MUST* only be used once, but it is not considered
#   secret and can be transmitted or stored alongside the ciphertext. A
#   good source of nonces are just sequences of 24 random bytes.

nonce = nacl.utils.random(nacl.secret.SecretBox.NONCE_SIZE)

print("24 byte nonce = " + str(nonce))

encrypted = box.encrypt(message, nonce)

# since we are transmitting the nonce by some other means,
# we just need to get the ciphertext and authentication data

ctext = encrypted.ciphertext

print("encrypting message without nonce - length of encrypted message + authentication MAC = " + str(len(ctext)))

print("macbytes = " + str(box.MACBYTES))
# ctext is just nacl.secret.SecretBox.MACBYTES longer
# than the original message

assert len(ctext) == len(message) + box.MACBYTES

# Decrypt our message, an exception will be raised if the encryption was
#   tampered with or there was otherwise an error.
plaintext = box.decrypt(encrypted)
print("decrypted message = " + plaintext.decode('utf-8'))
