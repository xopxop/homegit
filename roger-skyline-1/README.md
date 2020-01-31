# Roger-skyline-1
What I have learn from project Roger-skyline-1:
+ Basic installing a VM (in this case: debian 10), partioning the disk size and understand the different between the actual disk size and the one when setting up the VM.
+ How to set up a static IP address.
+ More practice with SSH command.
+ Seting up fire wall (ufw in this case) and enable the necessary port for a server machine (in this case: a log-in website).
+ Seting up the `fail2ban` for preventing DOS attack and set its configuration file, `portsentry` for preventing port scaning and `iptables` for showing the blocked IP address
+ Working with `cron` service and mail service.
+ How to set up a log-in website with apache2 and self signed certificate it.

## MANDATORY PART
### VM Part
You have to run a Virtual Machine (VM) with the Linux OS of your choice (Debian
Jessie, CentOS 7...) in the hypervisor of your choice (VMWare Fusion, VirtualBox...).
• A disk size of 8 GB.
• Have at least one 4.2 GB partition.
• It will also have to be up to date as well as the whole packages installed to meet
the demands of this subject.

*My VM (set-up)*
+ DEBIAN 10.2
+ Disk size of 8GB
+ one partition with 4.2 GB
In order to check for the size of disk, run the command: 
sudo fdisk -l
Note: when partioning the disk size, the primary disk should be some where around 4.5G, therefore when fdisk, the system disk will be around 4.2GB
because the size when partioning and the one which was shown by the system is different

*SOURCE:*[What size should I make a partition to appear as a standard number e.g 100Gb](https://superuser.com/questions/217012/what-size-should-i-make-a-partition-to-appear-as-a-standard-number-e-g-100gb)

### Network and Security Part
For the network on your VM, here are the steps to achieve

***You must create a non-root user to connect to the machine and work.***

non-root user: dthan

***Use sudo, with this user, to be able to perform operation requiring special rights.***

In order to use sudo command, first we have to install as root user:
```
$ su
# apt-get update -y && apt-get upgrade -y
# apt-get install sudo
```
Optional: Installing vim
```
# apt-get install vim
```
How to use ```sudo``` command with this user? we just need to modify and add ```user_name ALL=(ALL:ALL)``` in a file with a path ```/etc/sudoers```

<img src="pictures/Screen%20Shot%202020-01-22%20at%205.39.17%20PM.png" width = "300" height = "80" >

In order to check the special rights: use this command ```sudo -l -U user_name```

***We don’t want you to use the DHCP service of your machine. You’ve got to configure it to have a static IP and a Netmask in \30.***

To use the static IP, we need to modify this file ```/etc/network/interfaces``` from:

<img src="pictures/Screen%20Shot%202020-01-22%20at%206.17.38%20PM.png" width = "300" height = "80" > to <img src="pictures/Screen%20Shot%202020-01-22%20at%206.18.09%20PM.png" width = "300" height = "80" >

then creat a new file ```enp0s3``` then modify ```/etc/network/interfaces.d/enp0s3``` with these the new ip address, netmask in \30 and gateway address:

<img src="pictures/Screen%20Shot%202020-01-22%20at%206.50.21%20PM.png" width = "400" height = "80">

remember to restart the networking service with the command ```sudo service networking restart```
and using command ```ip address``` to check the result

***You have to change the default port of the SSH service by the one of your choice. SSH access HAS TO be done with publickeys. SSH root access SHOULD NOT be allowed directly, but with a user who can be root.***

*Changing the default port of the SSH server by the one of your choice*

To choose the port that we want to access SSH server, we need to modify the ssh configuartion file ```/etc/ssh/sshd_config```, locate the the port line and change it to the one that we one as well as the comment ```#``` ex: changing port 22 to port 55555
https://fi.godaddy.com/help/changing-the-ssh-port-for-your-linux-server-7306
NOTE: To check the available port, run command ```netstat -tulpn | grep LISTEN``` or ```ss -tulwn``` to see which port is activate

*Accessing SSH service with publickeys*

Step 1: Generating a pair of public and private key, on the host machine
```ssh-keygen -t rsa``` to generate the key. In the directory ```~\.ssh```, we can find 2 files which is the just generated key ```id_sra``` (private key) and ```id_rsa.pub``` (public key)
NOTE:
+ id_rsa: Private key, which should be kept safely and can be crypted with a password
+ id_rsa.pub: Public key, which we need to send it to the server (in this case out guest machine)

Step 2: Sending public key to the server (guest machine)
```ssh-copy-id -i id_rsa.pub <user_name>@<ip_address> -p <port_number>```
ex: ```ssh-copy-id -i id_rsa.pub dthan@10.12.1.109 -p 55555```
The key will be automatically added to the ```~/.ssh/authorized_keys``` on the server (guest machine)

*Disabling SSH root access*

Going back to the ssh configuration file ```/etc/ssh/sshd_config``` and locate then modify the line ```# PermitRootLogin yes``` to ```PermitRootLogin no``` https://mediatemple.net/community/products/dv/204643810/how-do-i-disable-ssh-login-for-the-root-user
NOTE: https://superuser.com/questions/1006267/why-should-i-really-disable-root-ssh-login
*Remove Password Authentification*

Change ```#PasswordAuthentication yes``` to ```PasswordAuthentication no```, so no need to type password when logging the server with SSH

Restart the SSH service
```sudo service ssh restart```

***You have to set the rules of your firewall on your server only with the services used outside the VM.***

*Installing UFW (Uncomplicated Firewall)*

UFW was a simple and easy to set-up, in oder to run UFW, we need to install UFW into the system with

```
sudo apt-get install ufw
sudo ufw status
sudo ufw enable
```
*Allowing access ports*
```
sudo ufw allow 55555/tcp
sudo ufw allow 80/tcp
sudo ufw allow 443/tcp
```
Now let check the status of ufw:
```sudo ufw status```
Expected result:

<img src="pictures/Screen%20Shot%202020-01-23%20at%205.14.10%20PM.png" width = "330" height = "139">

***You have to set a DOS (Denial Of Service Attack) protection on your open port of your VM.***

*SOURCE: List of DOS protection method*[CentOS DDoS protection](https://bobcares.com/blog/centos-ddos-protection/)

DOS protection service: Fail2Ban

Install Fail2Ban
```
$ sudo apt-get install fail2ban iptables apache2 -y
```
Fail2Ban configuration file `/etc/fail2ban/jail.conf`, We will make a copy of the file `jail.conf` and name it `jail.local`. In this way, if there is any change in the `jail.conf` update, out confirguarion for Fail2Ban will be kept the same.

1. Secure the SSH by edditing `/etc/fail2ban/jail.local`:

2. Secure the HTTP (port 80) by eddint `/etc/fail2ban/jail.local`:

3. Create a filter by creating the file /etc/fail2ban/filter.d/http-get-dos.conf and copy the text below in it:

```
# Fail2Ban configuration file
#
# Author: http://www.go2linux.org
#
[Definition]

# Option: failregex
# Note: This regex will match any GET entry in your logs, so basically all valid and not valid entries are a match.
# You should set up in the jail.conf file, the maxretry and findtime carefully in order to avoid false positives.

failregex = ^ -.*GET

# Option: ignoreregex
# Notes.: regex to ignore. If this regex matches, the line is ignored.
# Values: TEXT
#
ignoreregex =
```

***You have to set a protection against scans on your VM’s open ports.***

*SOURCE:*
+ [How to protect against port scanners?](https://unix.stackexchange.com/questions/345114/how-to-protect-against-port-scanners)
+ [To protect against the scan of ports with portsentry](https://en-wiki.ikoula.com/en/To_protect_against_the_scan_of_ports_with_portsentry)

Install Portsentry
```
$ sudo apt-get install portsentry
```
Modify the file ``/etc/default/portsentry``

<img src = "pictures/Screen%20Shot%202020-01-25%20at%2012.52.02%20PM.png" width = "296" height = "90" >

Activate BLOCK_UDP & BLOCK_TCP by changing to 1 the file `/etc/portsentry/portsentry.conf`

<img src = "pictures/Screen%20Shot%202020-01-25%20at%2012.57.52%20PM.png" width = "454" height = "430" >

Opting for blocking of malicious persons throught iptables. Therefore will need to disable all these KILL_ROUTE lines except this one:
```
KILL_ROUTE="/sbin/iptables -I INPUT -s $TARGET$ -j DROP"
```
Check the actions:
```
$ cat portsentry.conf | grep KILL_ROUTE | grep -v "#"
```
Restart Portsentry
```
$ sudo service portsentry restart
```

***Stop the services you don’t need for this project.***

*SOURCE: [List of available services](https://unix.stackexchange.com/questions/108591/list-of-available-services)*
To list all the service
```
$ ls /etc/init.d
or
$ sudo service --status-all
```

<img src="pictures/Screen%20Shot%202020-01-25%20at%201.17.46%20PM.png" width = "355" height = "324" >

Disable buletooth.service, console-setup.service & keyboard-setup.service
```
$ sudo systemctl disable console-setup.service
$ sudo systemctl disable keyboard-setup.service
```

***Create a script that updates all the sources of package, then your packages and which logs the whole in a file named /var/log/update_script.log. Create a scheduled task for this script once a week at 4AM and every time the machine reboots.***

```
$ touch i_will_update.sh
$ chmod a+x i_will_update.sh
```

<img src = "pictures/Screen%20Shot%202020-01-25%20at%201.31.17%20PM.png" width = "380" height = "53" >


Changing crontab by edditing cron job:
```
$sudo crontab -e
```

<img src="pictures/Screen%20Shot%202020-01-25%20at%201.41.02%20PM.png" width = 320 height = 58>

***Make a script to monitor changes of the /etc/crontab file and sends an email to root if it has been modified. Create a scheduled script task every day at midnight.***

```
$ touch i_will_monitor_cron.sh
$ chmod a+x i_will_monitor_con.sh
```

## OPTIONAL PART

***Web Part***

*This is my login page*

<img src="pictures/" width = "???" height = "???" >

*In order to have your own login page*
1. Find your own login page (ex: [html5 and css3 login forms](https://colorlib.com/wp/html5-and-css3-login-forms/))
2. Copy the webpage directory into directory ```/var/www/html/``` 

Remember delete every files which was in that directory before moving the login webpage

*Self-Signed SSL*
*SOURCE: [How To Create a Self-Signed SSL Certificate for Apache in Debian 9](https://www.digitalocean.com/community/tutorials/how-to-create-a-self-signed-ssl-certificate-for-apache-in-debian-9)*
1. Creating the SSL Certificate

```
sudo openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/apache-selfsigned.key -out /etc/ssl/certs/apache-selfsigned.crt
```
Output Promt

```
Country Name (2 letter code) [AU]:FI
State or Province Name (full name) [Some-State]:Uusima
Locality Name (eg, city) []:Helsinki
Organization Name (eg, company) [Internet Widgits Pty Ltd]:
Organizational Unit Name (eg, section) []:
Common Name (e.g. server FQDN or YOUR name) []:
Email Address []:root@debian.lan
```
2. Configuring Apache to Use SSL

*Creating an Apache Configuration Snippet with Strong Encryption Settings*

We first need to creat a new snippet in the ```/etc/apache2/conf-available``` directory and name the file ```ssl-params.conf``` to make its purpose clear:
```
sudo nano /etc/apache2/conf-available/ssl-params.conf
```
Paste the following configuration into the ```ssl-params.conf``` file
```
SSLCipherSuite EECDH+AESGCM:EDH+AESGCM:AES256+EECDH:AES256+EDH
SSLProtocol All -SSLv2 -SSLv3 -TLSv1 -TLSv1.1
SSLHonorCipherOrder On
# Disable preloading HSTS for now.  You can use the commented out header line that includes
# the "preload" directive if you understand the implications.
# Header always set Strict-Transport-Security "max-age=63072000; includeSubDomains; preload"
Header always set X-Frame-Options DENY
Header always set X-Content-Type-Options nosniff
# Requires Apache >= 2.4
SSLCompression off
SSLUseStapling on
SSLStaplingCache "shmcb:logs/stapling-cache(150000)"
# Requires Apache >= 2.4.11
SSLSessionTickets Off
```
*Modifying the Default Apache SSL Virtual Host File*
+ Back up the original SSL Virtual Host file
```
$ sudo cp /etc/apache2/sites-available/default-ssl.conf /etc/apache2/sites-available/default-ssl.conf.bak
```
+ Open the SSL Vitual Host file to make adjustment
```
sudo nano /etc/apache2/sites-available/default-ssl.conf
```
Edit the inside like this
```
<IfModule mod_ssl.c>
        <VirtualHost _default_:443>
                ServerAdmin your_email@example.com
                ServerName server_domain_or_IP

                DocumentRoot /var/www/html

                ErrorLog ${APACHE_LOG_DIR}/error.log
                CustomLog ${APACHE_LOG_DIR}/access.log combined

                SSLEngine on

                SSLCertificateFile      /etc/ssl/certs/apache-selfsigned.crt
                SSLCertificateKeyFile /etc/ssl/private/apache-selfsigned.key

                <FilesMatch "\.(cgi|shtml|phtml|php)$">
                                SSLOptions +StdEnvVars
                </FilesMatch>
                <Directory /usr/lib/cgi-bin>
                                SSLOptions +StdEnvVars
                </Directory>

        </VirtualHost>
</IfModule>
```
*(Recommended) Modifying the HTTP Host File to Redirect to HTTPS*
```
sudo nano /etc/apache2/sites-available/000-default.conf
```
Edit the ```000-default.conf``` which looks like this
```
<VirtualHost *:80>
        . . .

        Redirect "/" "https://your_domain_or_IP/"

        . . .
</VirtualHost>
```
3. Adjusting the Firewall

*NOTE: Already did when setting up rules for ufw*

4. Enabling the Changes in Apache
```
$ sudo a2enmod ssl
$ sudo a2enmod headers
$ sudo a2ensite default-ssl
$ sudo a2enconf ssl-params
$ sudo apache2ctl configtest
NOTE: expected OUT PUT
Syntax OK
$ sudo systemctl restart apache2
```
Now the SSL server is tested on the host's web browser and type ```https://``` followed by the server's domain name or IP into the address bar
```
https://server_domain_or_IP
```

### Deployment Part
