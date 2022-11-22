fallocate -l 100M lofs.img

sudo losetup -fP lofs.img
sudo mkfs.ext4 lofs.img

mkdir lofsdisk
sudo mount -o loop lofs.img lofsdisk
