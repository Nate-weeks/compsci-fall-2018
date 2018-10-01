import nacl.encoding
import nacl.hash
from nacl.bindings.utils import sodium_memcmp

HASHER = nacl.hash.sha256
# could be nacl.hash.sha512 or nacl.hash.blake2b instead

# define a 1024 bytes log message
input = input("what message would like to send to alice? \n")
msg = bytes(input, 'utf-8')
encoded_message = nacl.encoding.HexEncoder.encode(msg)
digest = HASHER(msg, encoder=nacl.encoding.HexEncoder)

# now send msg and digest to the user
print("creating digest from hash function")
print(digest)

# we received a 1024 bytes long message and it hex encoded digest
received_msg = nacl.encoding.HexEncoder.decode(encoded_message)

dgst = digest

# mess with the message and check to see if the digest is the same
print("shortening and modifying message to see if the recalculated hash matches")
print("original message: ")
print(received_msg)
shortened = received_msg[:-1]
modified = b'modified' + received_msg[:-8]
print(b"shorteded message: " + shortened)
print(b"modified message" + modified)

orig_dgs = HASHER(received_msg, encoder=nacl.encoding.HexEncoder)
shrt_dgs = HASHER(shortened, encoder=nacl.encoding.HexEncoder)
mdfd_dgs = HASHER(modified, encoder=nacl.encoding.HexEncoder)

# return equals if digest is the same, else return is different from
def eq_chk(dgs0, dgs1):
    if sodium_memcmp(dgs0, dgs1):
        return 'equals'
    return 'is different from'

MSG = 'Digest of {0} message {1} original digest'

for chk in (('original', orig_dgs),
            ('truncated', shrt_dgs),
            ('modified', mdfd_dgs)):

    print(MSG.format(chk[0], eq_chk(dgst, chk[1])))
