package main

import (
	"fmt"
	"os/exec"
	"strings"

	"github.com/shirou/gopsutil/host"
	"golang.org/x/text/cases"
	"golang.org/x/text/language"
)

func main() {
	info, err := host.Info()
	if err != nil {
		fmt.Printf("Error getting host info: %v\n", err)
		return
	}
	cmd := exec.Command("uname", "-m")
	arch, err := cmd.Output()
	if err != nil {
		fmt.Printf("Error executing uname -m: %v\n", err)
		return
	}
	c := cases.Title(language.Und)
	fmt.Printf("Hostname: %s\n", info.Hostname)
	fmt.Printf("OS: %s\n", c.String(info.OS))
	fmt.Printf("Platform: %s\n", c.String(info.Platform))
	fmt.Printf("PlatformVersion: %s\n", info.PlatformVersion)
	fmt.Printf("KernelVersion: %s\n", info.KernelVersion)
	fmt.Printf("Machine: %s\n", strings.TrimSpace(string(arch)))
}
